#ifndef INTEGER_H
#define INTEGER_H 
#include<string>
#include<iostream>

class Integer
{
public:
	Integer();
	Integer(const int &a);
	Integer(const long& i);
	Integer(const std::string& i);
	Integer(const char* i);
	Integer(char* i);
	void operator= (const int& i);
	void operator= (const long& i);
	void operator= (const std::string& i);
	void operator= (const char* i);
	void operator= (char* i);
	void add(const Integer& l, const Integer& r);
	void subtract(const Integer& l, const Integer& r);
	friend std::ostream& operator<<(std::ostream& o,Integer i);
	friend Integer operator+(const Integer& l, const Integer& r);
	friend Integer operator-(const Integer& l, const Integer& r);
	friend Integer operator-(const Integer& l);
	friend Integer operator*(const Integer& l, const Integer& r);
	friend bool operator<(const Integer& l, const Integer& r);
	friend bool operator>(const Integer& l, const Integer& r);
	friend bool operator<=(const Integer& l, const Integer& r);
	friend bool operator>=(const Integer& l, const Integer& r);
	Integer operator++(int);
	Integer operator++();
	Integer operator--();
	Integer operator--(int);
	size_t size();
	const char* c_str();
	std::string to_string();
private:
	std::string number;
	char sign;
};

#endif // !INTEGER_H




#include "Integer.h"

#include<algorithm>

Integer::Integer()
{
	sign = '+';
	number.push_back('0');
}

Integer::Integer(const int& a)
{
	if (a < 0) sign = '-';
	else sign = '+';
	int i = abs(a);
	if (a == 0) number.push_back('0');
	else while (i) {
		number.push_back(i % 10 + 48);
		i /= 10;
	}
}

Integer::Integer(const long& i)
{
	if (i < 0) sign = '-';
	else sign = '+';

	long a = abs(i);
	if (a == 0) number.push_back('0');
	else while (a) {
		number.push_back(a % 10 + 48);
		a /= 10;
	}
}

Integer::Integer(const std::string& i)
{
	if (i.length() > 0 && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		number = i.substr(1);
	}

	
	std::reverse(number.begin(), number.end());
}

Integer::Integer(const char* i)
{
	if (*i != '\0' && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		i++;
		number = i;
	}

	std::reverse(number.begin(), number.end());
}

Integer::Integer(char* i)
{
	if (*i != '\0' && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		i++;
		number = i;
	}

	std::reverse(number.begin(), number.end());
}

void Integer::operator=(const int& i)
{
	number.clear();

	if (i < 0) sign = '-';
	else sign = '+';

	int a = abs(i);
	if (a == 0) number.push_back('0');
	else while (a) {
		number.push_back(a % 10 + 48);
		a /= 10;
	}
}

void Integer::operator=(const long& i)
{
	number.clear();

	if (i < 0) sign = '-';
	else sign = '+';

	long a = abs(i);
	if (a == 0) number.push_back('0');
	else while (a) {
		number.push_back(a % 10 + 48);
		a /= 10;
	}
}

void Integer::operator=(const std::string& i)
{
	if (i.length() > 0 && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		number = i.substr(1);
	}

	std::reverse(number.begin(), number.end());
}

void Integer::operator=(char* i)
{
	number.clear();
	if (*i != '\0' && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		i++;
		number = i;
	}
	std::reverse(number.begin(), number.end());
}

void Integer::operator=(const char* i)
{
	number.clear();
	if (*i != '\0' && (i[0] != '+' && i[0] != '-')) {
		sign = '+';
		number = i;
	}
	else {
		sign = i[0];
		i++;
		number = i;
	}
	std::reverse(number.begin(), number.end());
}

Integer Integer::operator++()
{
	
	*this = *this + 1;
	return *this;
}

Integer Integer::operator--()
{
	*this = *this - 1;
	return *this;
}

Integer Integer::operator--(int)
{
	Integer p = *this;
	*this = *this + 1;
	return p;
}

Integer Integer::operator++(int)
{
	Integer prev = *this;
	*this = prev+1;
	return prev;
}

size_t Integer::size()
{
	return number.length();
}

const char* Integer::c_str()
{
	return to_string().c_str();
}

std::string Integer::to_string()
{
	std::string r = number;
	while (!r.empty() && r.back() == '0') r.pop_back();
	if (r.empty()) r.push_back('0');
	if (sign == '-') r.push_back('-');
	std::reverse(r.begin(),r.end());

	return r;
}

std::ostream& operator<<(std::ostream& o,Integer i)
{
	o << i.to_string();
	return o;
}

void Integer::add(const Integer& l, const Integer& r)
{
	number.clear();
	size_t length = std::max(l.number.size(), r.number.size());
	int carry = 0;
	for (size_t i = 0; i < length; i++)
	{
		int f = 0, s = 0;
		if (i < l.number.size())
			f = l.number[i] - 48;
		if (i < r.number.size())
			s = r.number[i] - 48;

		int sum = f + s + carry;
		number.push_back(sum % 10 + 48);
		carry = sum / 10;
	}

	while (carry) {
		number.push_back(carry % 10 + 48);
		carry /= 10;
	}
	sign = l.sign;
}

void Integer::subtract(const Integer& l, const Integer& r)
{
	number.clear();

	bool left = l.number.size() == r.number.size() ? (l.number[l.number.size()-1] - 48 < r.number[l.number.size() - 1] - 48) ? false : true : l.number.size() > r.number.size() ? true : false;
	
	if (left) {
		int carry = 0;
		for (size_t i = 0; i < l.number.length(); i++)
		{
			int f = 0, s = 0;
			if (i < l.number.size())
				f = l.number[i] - 48;
			if (i < r.number.size())
				s = r.number[i] - 48;

			int sum = f + carry - s;
			if (sum < 0) {
				sum = f + carry - s + 10;
				carry = -1;
			}
			else {
				carry = 0;
			}
			number.push_back(sum % 10 + 48);
		}

		if (carry) {
			number.push_back(abs(carry) + 48);
		}
		
		sign = l.sign;

	}
	else {
		int carry = 0;
		for (size_t i = 0; i < r.number.length(); i++)
		{
			int f = 0, s = 0;
			if (i < r.number.size())
				f = r.number[i] - 48;
			if (i < l.number.size())
				s = l .number[i] - 48;

			int sum = f + carry - s;
			if (sum < 0) {
				sum = f + carry - s + 10;
				carry = -1;
			}
			else {
				carry = 0;
			}
			number.push_back(sum % 10 + 48);
		}

		if (carry) {
			number.push_back(abs(carry) + 48);
		}
		
		sign = r.sign;
	}
	
}

Integer operator+(const Integer& l, const Integer& r)
{
	Integer res;
	if (l.sign == r.sign) res.add(l, r);
	else res.subtract(l, r);
	return res;
}

Integer operator-(const Integer& l, const Integer& r)
{
	Integer res;
	Integer temp_r = r;
	if (temp_r.sign == '-') temp_r.sign = '+';
	else temp_r.sign = '-';
	if (temp_r.sign == l.sign) res.add(l, temp_r);
	else res.subtract(l, temp_r);
	return res;
}

Integer operator-(const Integer& l)
{
	return Integer();
}

Integer operator*(const Integer& l, const Integer& r)
{
	Integer res("");
	if (l.number.size() <= r.number.size()) {
		for (int i = 0; i < l.number.size(); i++) {
			int carry = 0;
			int index = i;
			for (int j = 0; j < r.number.size(); j++) {
				int m = ((l.number[i] - 48) * (r.number[j] - 48)) + carry;
				if (index < res.number.size()) {
					m = m + (res.number[index] - 48);
					res.number[index++] = m % 10 + 48;
				}
				else {
					index++;
					res.number.push_back(m % 10 + 48);
				}
				carry = m / 10;
			}
			while (carry) {
				if (index < res.number.size()) res.number[index++] = carry % 10 + 48;
				else res.number.push_back(carry % 10 + 48);
				carry /= 10;
			}
		}

	}
	else {
		for (int i = 0; i < r.number.size(); i++) {
			int carry = 0;
			int index = i;
			for (int j = 0; j < l.number.size(); j++) {
				int m = ((r.number[i] - 48) * (l.number[j] - 48)) + carry;
				if (index < res.number.size()) {
					m = m + (res.number[index] - 48);
					res.number[index++] = m % 10 + 48;
				}
				else {
					index++;
					res.number.push_back(m % 10 + 48);
				}
				carry = m / 10;
			}
			while (carry) {
				if (index < res.number.size()) res.number[index++] = carry % 10 + 48;
				else res.number.push_back(carry % 10 + 48);
				carry /= 10;
			}
		}
	}
	if (l.sign != r.sign) res.sign = '-';
	else res.sign = '+';
	return res;
}

bool operator<(const Integer& l, const Integer& r)
{
	if (l.number.size() < r.number.size())
		return true;
	else if (l.number.size() == r.number.size()) {
		for (int i = l.number.length() - 1; i >= 0; i--)
		{
			if (l.number[i] == r.number[i]) continue;
			else if (l.number[i] < r.number[i]) return true;
			else return false;
		}
	}

	return false;
}

bool operator>(const Integer& l, const Integer& r)
{
	if (l.number.size() > r.number.size())
		return true;
	else if (l.number.size() == r.number.size()) {
		for (int i = l.number.length() - 1; i >= 0; i--)
		{
			if (l.number[i] == r.number[i]) continue;
			else if (l.number[i] > r.number[i]) return true;
			else return false;
		}
	}

	return false;
}

bool operator<=(const Integer& l, const Integer& r)
{
	return !(l>r);
}

bool operator>=(const Integer& l, const Integer& r)
{
	return !(l<r);
}



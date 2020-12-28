// Performance Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<chrono>
#include<iostream>

#include "Integer.h"

namespace tracker {
    class Timer {
    public:
        Timer() {
            startPoint = std::chrono::high_resolution_clock::now();
        }
        ~Timer() {
            const auto &endPoint = std::chrono::high_resolution_clock::now();
            const auto &start = std::chrono::time_point_cast<std::chrono::nanoseconds>(startPoint).time_since_epoch().count();
            const auto &end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endPoint).time_since_epoch().count();

            std::cout << "Exec time : " << (end - start)/1000000.0 << "ms" << std::endl;

        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startPoint;
    };

}

using namespace std;

Integer fact(int x) {
    Integer i = 1;
    while (x) {
        i = i * x;
        x--;
    }
    return i;
}

int main()
{


   /* int** arr = new int*[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = new int[20];
    }
    int a[400];
    memset(a, -1, sizeof(a));
    {
        tracker::Timer timer;
        for (int i = 0; i < 20; i++) {
            for (size_t j = 0; j < 20; j++)
            {
                cout << arr[i][j] << endl;
            }
        }

        for (size_t i = 0; i < 20; i++)
        {
            for (size_t j = 0; j < 20; j++)
            {
                cout << a[j + i * 20] << endl;
            }
        }
    }*/

    Integer n1 = "68768466767637265627636867865767236658623866766676476";
    Integer n2 = "977477877687875869784975867897498764857869784957689458677387487876834786276746618763657626564368734786978497697983";

    Integer n3 = 1000;
    Integer n4 = 1001;
    int n;
    //cin >> n;

    //cout << n3 < n4;

    Integer x = "8658638767867467";
    Integer y = "54545421245453454444";
    cout << n2 * y << endl;




    
   
    


}

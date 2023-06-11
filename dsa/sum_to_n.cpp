/* Recursion */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Summer
{
public:
    int num;
    Summer(int val)
    {
        this->num = val;
    }

    int sumToN(int n)
    {
        int sum = n;
        if (n == 1)
        {
            sum = 1;
            return sum;
        }
        else
        {
            return sum + sumToN(n - 1);
        }
    }
};

int main()
{
    Summer *obj = new Summer(4);
    cout << obj->sumToN(14);
    return 0;
}
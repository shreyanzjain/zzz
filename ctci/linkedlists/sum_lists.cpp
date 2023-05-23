#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()  {
    list<int> list1 = {7, 1, 6, 3};
    list<int> list2 = {5, 9, 2};
    list<int> sum_list;
    
    int ctr = 0;
    list<int> :: iterator itr1 = list1.begin();
    list<int> :: iterator itr2 = list2.begin();
    
    int val1 = 0, val2 = 0;
    
    while(itr1 != list1.end())  {
        val1 += (*itr1 * pow(10, ctr));
        itr1++;
        ctr++;
    }
    
    ctr = 0;
    while(itr2 != list2.end())  {
        val2 += (*itr2 * pow(10, ctr));
        itr2++;
        ctr++;
    }
    
    cout << val1 << "\t" << val2 <<endl;
    
    int sum = val1 + val2;
    cout << "sum: " << sum << endl;
    
    while(sum != 0) {
        sum_list.push_back(sum % 10);
        sum /= 10;
    }
    
    itr1 = sum_list.begin();
    while(itr1 != sum_list.end())    {
        cout << *itr1 << "\t";
        itr1++;
    }
    cout << endl;
}
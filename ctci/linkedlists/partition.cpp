#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()  {
    int x = 5;
    list<int> nums= {3, 5, 8, 5, 10, 2, 1};

    list<int> :: iterator first = nums.begin();
    list<int> :: iterator second = ++nums.begin();
    
    while(second != nums.end()) {
        if(*first < x)   {
            first++;
        }   else    {
            int temp = *first;
            *first = *second;
            *second = temp;
            second++;
        }
    }
    
    for(first = nums.begin(); first != nums.end(); first++) {
        cout << *first << "\t";
    }
    cout << "\n";
    return 0;
}
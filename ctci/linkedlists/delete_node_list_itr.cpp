#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    list<int> arr;
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    arr.resize(size);
    list<int>::iterator itr;
    cout << "Enter the elements: ";
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        int val;
        cin >> val;
        *itr = val;
    }

    int del;
    cout << "Enter a middle node to delete: ";
    cin >> del;

    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        if (*itr == del)
        {
            break;
        }
    }

    list<int>::iterator second = itr++;
    while (second != arr.end())
    {
        swap(*itr, *(second));
        itr++;
        second++;
    }

    arr.pop_back();
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *itr << "\t";
    }
    return 0;
}
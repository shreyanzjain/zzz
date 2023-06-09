/*
Find minimum element in the array at each pass and swap it with the current element
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums;
    int size;
    int target;
    int res = 0;

    // taking input
    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }
    int min;
    int index;

    for (int i = 0; i < nums.size(); i++)
    {
        min = nums[i];
        index = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < min)
            {
                min = nums[j];
                index = j;
            }
        }
        int temp = nums[i];
        nums[i] = min;
        nums[index] = temp;
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
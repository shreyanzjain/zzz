#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()  {
    vector<int> arr;
    int size;
    int target;
    int res = 0;

    // taking input
    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)  {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int left = 0;
    int right = arr.size() - 1;
    int mid;

    // First we find the left pivot, you can also do the same
    // with the right pivot

    while (left < right)    {
        mid = left + (right - left) / 2;
        if (arr[mid] >= arr[0]) {
            if(arr[left] > arr[right])  {
                right = mid - 1;
            }   else    {
                left = mid + 1;
            }
        }
        else    {
            right = mid - 1;
        }
    }

    cout << "Enter the value to lookup: ";
    cin >> target;

    // if the target is greater than the first value, it means the 
    // target exists on the first half
    // else it exists on the second half
    if(target < arr[0]) {
        left = left + 1;
        right = arr.size() - 1;
    }   else    {
        right = left;
        left = 0;
    }

    int flag = -1;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(arr[mid] == target)  {
            cout << "Found element at: " << mid << endl;
            flag = 0;
            break;
        }   else if(target > arr[mid])  {
            left = mid + 1;
        }   else    {
            right = mid - 1;
        }
    }

    if(flag == -1)  {
        cout << "Element does not exist in the array." << endl;
    }
}
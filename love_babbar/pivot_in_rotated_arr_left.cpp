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

    cout << "Pivot element: " << arr[left] << endl;
    return 0;
}
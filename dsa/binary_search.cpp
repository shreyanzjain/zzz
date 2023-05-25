#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()  {
    vector<int> nums = {1, 3, 7, 9, 11, 15, 21, 25, 31};
    int left = 0;
    int right = nums.size();
    
    int target;
    cout << "Enter the number to search for: ";
    cin >> target;
    int mid;
    
    while(left < right) {
        mid = (left + right) / 2;
        if(target == nums[mid]) {
            cout << "Found: "<< target <<" at: "<< mid;
            return 0;
        }   else    {
            if(target > mid)    {
                left = mid;
            }   else    {
                right = mid;
            }
        }
    }
    
    cout << "Number not found!";
    return 0;
}
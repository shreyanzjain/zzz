#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum
// TC: O(N) -> Sliding Window
// SC: O(N) -> Arrays to store the current window state

int findMaxSum(vector<int>& arr, int k, vector<int>& dummy){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxSum;
    vector<int> currElements;

    // initialize the sum
    while(r < k){
        currElements.push_back(arr[r]);
        sum += arr[r];
        r++;
    } 

    maxSum = sum;

    while(r < arr.size()){
        sum = sum - arr[l];
        currElements.erase(currElements.begin());
        
        sum = sum + arr[r];
        currElements.push_back(arr[r]);

        if (sum > maxSum){
            maxSum = sum;
            dummy = currElements;
        }

        l++;
        r++;
    }

    return maxSum;
}


// Driver Code
int main(){
    int n, window_size, maxSum;
    vector<int> arr;
    vector<int> dummy;
    cout << "Enter the number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Enter size of the window: ";
    cin >> window_size;

    maxSum = findMaxSum(arr, window_size, dummy);
    cout << "Max sum: "<< maxSum<< endl;
    cout << "Elements: ";
    for(int i = 0; i < dummy.size(); i++){
       cout << dummy[i] << " ";
    }

    return 0;
}
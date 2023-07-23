/*
    Insertion sort inserts elements into the result container in a sorted way
    Given: 5 2 7 9 6
    1. 5
    2. 2 < 5 => 2 5
    3. 7 > 5 => 2 5 7
    4. 9 > 7 => 2 5 7 9
    5. 6 < 9 => 2 5 7 6 9; 6 < 7 => 2 5 6 7 9; 6 > 5 => 2 5 6 7 9
                -- Sorted --
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap_in_place(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

vector<int> insertion_sort(vector<int>& arr){
    vector<int> res;

    for(int i = 0; i < arr.size(); i++){
        res.push_back(arr[i]);

        for(int j = i; j > 0; j--){
            // if it is the first iteration of the outer loop
            if(i == 0){
                break;
            }

            if(res[j] < res[j - 1]){
                swap_in_place(res[j], res[j - 1]);
            }   else{
                break;
            }
        }
    }
    return res;
}

int main(){
    int n; 
    cin >> n;

    vector<int> arr;
    int val;

    for(int i = 0; i < n; i++){
        cin >> val;
        arr.push_back(val);
    }

    arr = insertion_sort(arr);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }   cout << endl;

    return 0;
}
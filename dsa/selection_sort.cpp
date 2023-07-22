/*
Find minimum element in the array at each pass and swap it with the current element
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap_in_place(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    cin >> n;
    int val;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> val;
        arr.push_back(val);
    }

    for(int i = 0; i < n; i++){
        // assuming that the current element is smallest
        int smallest_idx = i;

        for(int j = i + 1; j < n; j++){
            // if there is a smaller element, then update the smallest_idx
            if(arr[j] < arr[smallest_idx]){
                smallest_idx = j;
            }
        }
        swap_in_place(arr[i], arr[smallest_idx]);
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }   cout << endl;
    return 0;
}

// Follow Up:  Is this a stable or an unstable algorithm?
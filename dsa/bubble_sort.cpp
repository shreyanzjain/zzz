/*
Elements bubble to the right in each run
Run 1: 
Init State: 1 10 7 6 14 9
1. 1 < 10 => Nothing happens
2. 10 > 7 => Swap: 1 7 10 6 14 9
3. 10 > 6 => Swap: 1 7 6 10 14 9
4. 10 < 14 => Nothing happens
5. 14 > 9 => Swap: 1 7 6 10 9 14

        --Run 1 ends --
And so on, till the final result: 1 6 7 9 10 14
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap_in_place(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size() - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap_in_place(arr[j], arr[j + 1]);
            }
        }
    }
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

    bubbleSort(arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }   cout << endl;

    return 0;
}
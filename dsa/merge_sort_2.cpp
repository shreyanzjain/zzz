/*
Merge sort
*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int s, int e){
    int mid = s + (e - s) / 2;
    int len1 = mid - s  + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    int k = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[k];
        k++;
    }

    int idx1 = 0, idx2 = 0, mainArrayIdx = s;

    while(idx1 < len1 && idx2 < len2){
        if(first[idx1] < second[idx2]){
            arr[mainArrayIdx] = first[idx1];
            idx1++;
        }   else{
            arr[mainArrayIdx] = second[idx2];
            idx2++;
        }
        mainArrayIdx++;
    }

    while(idx1 < len1){
        arr[mainArrayIdx] = first[idx1];
        mainArrayIdx++;
        idx1++;
    }

    while(idx2 < len2){
        arr[mainArrayIdx] = second[idx2];
        mainArrayIdx++;
        idx2++;
    }
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s >= e){
        return ;
    }

    int mid = s + (e - s) / 2;

    //left half
    mergeSort(arr, s, mid);

    //right half
    mergeSort(arr, mid + 1, e);

    //merge sorted arrays
    merge(arr, s, e);
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

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }   cout << endl;

    return 0;
}
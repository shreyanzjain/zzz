/**
 * Selection sort is a sorting algo
 * that sorts a list by repeatedly
 * selecting the smallest or the largest element
 * depending on the order of what you want
 * elements to be sorted in
 */

#include <iostream>

using namespace std;

class SelectionSort {
    public:
        void selection_sort(int arr[], int n) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(arr[j] > arr[i]) {
                        int tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                    }
                }
            }
        }
};

int main() {
    int arr[] = {1, 9 , 0, -1, 77, 66};
    int n = (sizeof(arr) / sizeof(arr[0]));

    SelectionSort selectionSort;
    selectionSort.selection_sort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
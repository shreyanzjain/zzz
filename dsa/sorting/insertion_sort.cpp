/**
 * Insertion sort works by sorting
 * elements a section at a time
 * i.e. a sorted section is maintained which is populated
 * by items picked up from the unsorted section
 * -> sorted: {1, 2, 3} <=> unsorted: {9, 4, 5, 0}
 */

#include <iostream>

using namespace std;

class InsertionSort {
    public:
        void insertion_sort(int arr[], int n) {
            int sorted_end = 0;
            int unsorted_start = 1;

            // we take n - 1 as if sorted_end reaches n - 1 
            // then unsorted_start goes out of bounds
            while(sorted_end < n - 1) {
                int i = sorted_end;
                int j = unsorted_start;
                while(i >= 0) {
                    if(arr[j] < arr[i]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        j = i;
                        i--;
                    } else {
                        break;
                    }
                }
                sorted_end++;
                unsorted_start++;
            }
        }
};

int main() {
    int arr[] = {1, 9 , 0, -1, 77, 66, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort insertionSort;
    insertionSort.insertion_sort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
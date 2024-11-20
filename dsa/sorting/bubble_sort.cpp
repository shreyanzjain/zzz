/**
 * Bubble sot is a sorting algo.
 * that compares an element with its adjacent elements
 * and moves it to the correct position
*/

#include <iostream>
using namespace std;

class BubbleSort {
    public:
        void bubble_sort(int arr[], int n) {
            int curr = 0;
            while(curr < n) {
                int i = curr - 1;
                while(i >= 0) {
                    if(arr[curr] > arr[i]) {
                        int temp = arr[i];
                        arr[i] = arr[curr];
                        arr[curr] = temp;
                        curr--;
                        i--;
                    } else {
                        break;
                    }
                }
                curr++;
            }
        }
};

int main() {
    int arr[] = {1, 9 , 0, -1, 77, 66, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort bubbleSort;
    bubbleSort.bubble_sort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
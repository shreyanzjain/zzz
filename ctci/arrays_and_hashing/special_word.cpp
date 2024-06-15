#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int start = 1;
    int end = n * n + 1;
    int num = n;

    // Calculate the number of spaces before the first number in each row
    int numSpaces = 0;

    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int s = 0; s < numSpaces; s++) {
            std::cout << " ";
        }

        // Print the first set of numbers in each row
        for (int j = 0; j < num; j++) {
            std::cout << start << " ";
            start++;
        }

        // Calculate and print spaces between two sets of numbers
        // for (int s = 0; s < 2 * (n - num); s++) {
        //     std::cout << "  ";
        // }

        // Print the second set of numbers in each row
        for (int j = 0; j < num; j++) {
            std::cout << end << " ";
            end++;
        }

        std::cout << std::endl;

        // Update the number of spaces and end number for the next row
        numSpaces += 2;
        num--;
        end = end - (num * 2) - 1;
    }

    return 0;
}

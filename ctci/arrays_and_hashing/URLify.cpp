#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void swapChars(char &a, char &b);

int main() {
    string s = "  Mr John Snow        ";
    int end = s.length() - 1;
    // find the last non-space character
    while(s[end] == 0x20){
        end--;
    }
    // from the start look for all spaces until the first non-space character
    // track spaces till the first non-space character
    // once you find the first non-space character you will have a window starting and ending with
    // a non-space character
    // shift elements of this window to the right 2 * number of spaces to create space
    // for filling %20 at all the previously counted spaces
    // start filling %20 from the first space to the start of the window
    // repeat this process inside the window
    int left = 0;
    int first_space_pos = s.length() - 1; // assuming the first space occurs at the end 
    int right = s.length() - 1;
    // counts the number of spaces
    int ctr = 0;
    while(left < right) {
        // if the character is a zero
        if(s[left] == 0x20) {
            if(left < first_space_pos)  {
                first_space_pos = left;
            }
            ctr++;
            left++;
        }   else {
            if(ctr != 0) {
                int tmp_left = left;
                for(int i = end; i >= left; i--) {
                    swapChars(s[i], s[(ctr * 2 ) + i]);
                }
                // shift left and end to their new positions
                // that is 2 * ctr ahead from their original
                end = end + (2 * ctr);
                left = left + (2 * ctr);
                for(int i = first_space_pos; i < left; i = i + 3) {
                    s[i] = '%';
                    s[i + 1] = '2';
                    s[i + 2] = '0';
                }
                first_space_pos = right;
                ctr = 0;
            }  else {
                left++;
            } 
        }
    }
    cout << "\""<< s << "\"";
    return 0;
}

void swapChars(char &a, char &b){
    char tmp = a;
    a = b;
    b = tmp;
}
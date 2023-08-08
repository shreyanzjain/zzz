// check if a string has all unique characters (case sensitive)
// do not use additional data structures

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void method1(string& s){
    bool unique = true;

    // check for every element if it exists in the string to the right of it
    // eg. shreyans:
    // -> first we check if 's' exists to the right of the initial 's' and it does
    // so the string is not unique
    // TC: O(n^2); where, n = s.size();

    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            if(s[i] == s[j]){
                cout << "Not Unique" << endl;
                unique = false;
            }
        }
        if(!unique){
            break;
        }
    }
    if(unique){
        cout << "Unique" << endl;
    }
}

void method2(string& s){
    bool unique = true;
    
    // sort the string, then
    // check if the next character is the same as the current character
    // TC: nlog(n); which is the TC of merge sort

    sort(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i+1]){
            unique = false;
        }
        if(!unique){
            cout << "Not Unique" << endl;
            break;
        }
    }
    if(unique){
        cout << "Unique" << endl;
    }
}

int main(){
    string s;
    cin >> s;
    
    method1(s);
    method2(s);
    return 0;
}
// Given two strings check whether one is a permutation of the other
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
void checkPermutationBySort(string s1, string s2);
void checkPermutationByMap(string s1, string s2);

int main(){
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    checkPermutationBySort(s1, s2);
    return 0;
}

void checkPermutationBySort(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << s1 << endl;
    cout << s2 << endl;

    if(s1 == s2){
        cout << "Permutation" << endl;
    }   else{
        cout << "Not Permutation" << endl;
    }
}

void checkPermutationByMap(string s1, string s2){
    
}
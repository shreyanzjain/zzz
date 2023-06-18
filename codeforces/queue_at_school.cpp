// https://codeforces.com/problemset/problem/266/B
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int t;
    cin >> t;
 
    string s = "";
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        s += c;
    }
 
    if(n == 1){
        cout << s << endl;
        return 0;
    }
 
    for(int i = 0; i < t; i++){
        for(int i = 0; i < n; i++){
            if(s[i] == 'B' && i < n - 1){
                if(s[i + 1] == 'G'){
                    swap(s[i], s[i+1]);
                    i++;
                }
            }
        }
    }
 
    cout << s << endl;
}
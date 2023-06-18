// https://codeforces.com/problemset/problem/272/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum_of_fingers = 0;
    int ways = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        sum_of_fingers += val;
    }

    for(int i = 1; i <= 5; i++){
        if((sum_of_fingers + i) % (n + 1) != 1){
            ways++;
        }
    }

    cout << ways << endl;
    return 0;
}
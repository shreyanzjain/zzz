// https://codeforces.com/problemset/problem/227/B
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> index;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        index[x] = i;
    }

    int m;
    cin >> m;
    long long vasya_count = 0, petya_count = 0;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        vasya_count += index[x] + 1;
        petya_count += n - index[x];
    }

    cout << vasya_count << " " << petya_count << endl;
    return 0;
}
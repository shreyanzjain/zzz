#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int fibonacci(int n) {
        if(n == 2 || n == 1) {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {
    Solution* obj;
    cout << obj->fibonacci(25);
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int factorial(int num) {
        if(num == 1) {
            return 1;
        }
        return num * factorial(num - 1);
    }
};

int main() {
    Solution* obj;
    cout << obj->factorial(8);
    return 0;
}
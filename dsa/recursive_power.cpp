#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    long rec_pow(int base, int power) {
        if(power == 1) {
            return base;
        }

        return base * rec_pow(base, power - 1);
    }
};

int main() {
    Solution* obj;
    cout << obj->rec_pow(4, 6);
    return 0;
}
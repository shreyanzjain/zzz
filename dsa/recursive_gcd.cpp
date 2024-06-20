#include <iostream>

class Solution{
    public:
    int gcd = 1;

    int min(int a, int b) {
        if(a > b) {
            return b;
        }
        return a;
    }

    int max(int a, int b) {
        if(a > b) {
            return a;
        }
        return b;
    }

    bool divides(int a, int b, int n) {
        if(a%n == 0) {
            if(b%n == 0){
                return true;
            }
        }
        return false;
    }

    int rec_gcd(int a, int b, int n) {
        if(n > min(a, b)) {
            return gcd;
        }
        if(divides(a, b, n)) {
            gcd = max(n, gcd);
        }
        return rec_gcd(a, b, n + 1);
    }
};

int main() {
    Solution obj;
    std:: cout << obj.rec_gcd(6, 15, 1);
    return 0;
}
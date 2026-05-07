#include <iostream>


int MOD_VALUE = 1000000007;
int main() {
int n;
std::cin >> n;
int val = 1;

for(int i = 0; i < n; i++) {
  val = (val * 2) % MOD_VALUE;
}

std::cout << val;
return 0;
}
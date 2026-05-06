#include <iostream>
#include <math.h>

int generateCostOfFive(int n) {
  int cost = 0;
  int i = 5;
  while(i <= n) {
    cost = cost + n / i;
    i = i * 5;
  }

  return cost;
}

int main() {
  int n;
  std::cin >> n;

  std::cout << generateCostOfFive(n) << std::endl;
}
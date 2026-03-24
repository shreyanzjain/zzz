#include <iostream>

void calcIter(long& n);

int main() {
  long n;
  std::cin >> n;
  std::cout << n << "\t";
  while(n != 1) {
    calcIter(n);
  }
  return 0;
}

void calcIter(long& n) {
  if(n % 2 == 0) {
    n = n / 2;
  } else {
    n = (3 * n) + 1;
  }
  std::cout << n << "\t";
}
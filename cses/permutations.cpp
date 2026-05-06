#include <iostream>

void generateBeautifulPermutation(int n, int formerStart, int latterStart);

int main() {
  int n;
  std::cin >> n;

  switch (n) {
    case 1:
      std::cout << 1;
      break;
    case 2:
    case 3:
      std::cout << "NO SOLUTION";
      break;
    case 4:
      generateBeautifulPermutation(n, 2, 1);
      break;
    default:
      generateBeautifulPermutation(n, 1, 2);
      break;
  }
  return 0;
}

/**
 * @brief function to generate a beautiful permutation based on cses - Permutations
 * 
 * @param n - the length of the permutation
 * @param formerStart - the starting number of the first half
 * @param latterStart - the starting number of the second half
 */
void generateBeautifulPermutation(int n, int formerStart, int latterStart) {
  for(int i = formerStart; i <= n; i = i + 2) {
    std::cout << i << "\t";
  }

  for(int i = latterStart; i <= n; i = i + 2) {
    std::cout << i << "\t";
  }

  return;
}
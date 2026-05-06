#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  int longest = 1;
  int current = 1;
  std::size_t idx = 1;
  while (idx < s.size())  {
    if(s[idx] == s[idx - 1]) {
      current++;
    } else  {
      longest = std::max(longest, current);
      current = 1;
    }

    idx++;
  }

  longest = std::max(longest, current);
  std::cout << longest;
  return 0;
}
#include <iostream>
#include <string>
#include <map>

bool isOdd(int n) {
  return n % 2 == 1;
}

bool palindromePossible(std::map<char, int> charCounts) {
  std::map<char, int> :: iterator itr;
  bool seenOdd = false;
  for(itr = charCounts.begin(); itr != charCounts.end(); itr++) {
    if(seenOdd && (isOdd(itr->second))) return false;
    if(!seenOdd && (isOdd(itr->second))) {
      seenOdd = true;
    }
  }

  return true;
}

int main() {
  std::string s;
  std::cin >> s;
  std::map<char, int> charCounts;
  std::string sol = "";
  char centerChar = 'a';
  int centerCount = 0;
  std::string firstHalf = "";

  for(char c : s) {
    charCounts[c]++;
  }

  bool isPalindromePossible = palindromePossible(charCounts);
  if(isPalindromePossible) {
    for(auto itr = charCounts.begin(); itr != charCounts.end(); itr++) {
      if(isOdd(itr -> second)) {
        centerChar = itr -> first;
        centerCount = itr -> second;
        charCounts[itr -> first] = 0;
      } else {
        int currentCount = itr -> second / 2;
        while(currentCount > 0) {
          sol.push_back(itr -> first);
          currentCount--;
        }
      }
    }
    firstHalf = sol; //store the first half to reverse
    while(centerCount > 0) {
      sol.push_back(centerChar);
      centerCount--;
    }
    for(int i = firstHalf.size() - 1; i >= 0; i--) {
      sol.push_back(firstHalf[i]);
    }
    std::cout << sol << std::endl;
  } else {
    std::cout << "NO SOLUTION" << std::endl;
  }

  return 0;
}
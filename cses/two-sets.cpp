#include <iostream>
#include <vector>

void greedy(int n, long half){
  long required = half;
  std::vector<int> vec(n, 1);
  std::vector<int> h1;
  std::vector<int> h2;

  for(int i = n; i >= 1; i--) {
    if(i <= required) {
      h1.push_back(i);
      required -= (long)i;
    } else {
      h2.push_back(i);
    }
  }

  std::cout<<h1.size()<<std::endl;
  for(int i: h1) {
    std::cout<<i<<"\t";
  }
  std::cout<<std::endl;

  std::cout<<h2.size()<<std::endl;
  for(int i: h2) {
    std::cout<<i<<"\t";
  }
  std::cout<<std::endl;
}

int main() {
  int n;
  std::cin >> n;

  long x = ((long) n * ((long)(n + 1))) / 2L;
  if(x % 2 == 1) {
    std::cout << "NO" << std::endl;
  } else {
    long half = x / 2L;
    std::cout << "YES" << std::endl;
    greedy(n, half);
  }
  return 0;
}
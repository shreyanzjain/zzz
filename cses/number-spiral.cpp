#include <iostream>
#include <vector>

bool isOdd(int n) {
  return n % 2 == 1;
}

void runQuery(std::vector<int> qry) {
  int peakIdx = std::max(qry[0], qry[1]);
  int rowDiff = peakIdx - qry[0];
  int colDiff = peakIdx - qry[1];

  long long valAtCorner = ((long long)peakIdx * (long long)peakIdx) - ((long long)peakIdx - 1LL);
  if(rowDiff > 0) {
    std::cout << (isOdd(peakIdx) ? (valAtCorner + rowDiff) : (valAtCorner - rowDiff));
  } else if(colDiff > 0) {
    std::cout << (isOdd(peakIdx) ? (valAtCorner - colDiff) : (valAtCorner + colDiff));
  } else {
    std::cout << valAtCorner;
  }
  std::cout << "\n";

  return;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> queries;

  // obtain and store the queries
  for(int i = 0; i < n; i++) {
    std::vector<int> tmp;
    for(int j = 0; j < 2; j++) {
      int x;
      std::cin >> x;
      tmp.push_back(x);
    }
    queries.push_back(tmp);
  }


  // run the queries
  for(auto qry: queries) {
    runQuery(qry);
  }

  return 0;
}
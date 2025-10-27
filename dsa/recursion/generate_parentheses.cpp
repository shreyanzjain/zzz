// leetcode
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        vector<string> sols;

    public:
        void solve(int openN, int closedN, string output) {
            if(openN == 0 && closedN == 0) {
                sols.push_back(output);
                return;
            }

            if(openN > 0) {
                string op = output;
                op.push_back('(');
                solve(openN - 1, closedN, op);
            }

            if(closedN > openN) {
                string op = output;
                op.push_back(')');
                solve(openN, closedN - 1, op);
            }

            return;
        }

        void print() {
            for(auto& ele : sols) {
                cout << ele << "\t";
            }

            return;
        }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;

    sol.solve(n, n, "");
    sol.print();
    return 0;
}
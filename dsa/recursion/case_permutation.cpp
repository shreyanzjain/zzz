// ip - AB
// op - {ab, aB, Ab, AB}

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
    private:
        vector<string> perms;

    public:
        void solve(string ip, string op) {
            if(ip.length() == 0) {
                perms.push_back(op);
                return;
            }

            string op1 = op;
            op1.push_back(tolower(ip[0]));

            string op2 = op;
            op2.push_back(toupper(ip[0]));

            solve(ip.substr(1), op1);
            solve(ip.substr(1), op2);

            return;
        }

        void printPerms() {
            for(auto& ele : perms) {
                cout << "\"" << ele << "\"\t";
            }
        }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    sol.solve(s, "");
    sol.printPerms();

    return 0;
}
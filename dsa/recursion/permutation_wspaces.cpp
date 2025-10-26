// permutation of string with spaces
// ip = AB
// op = {"AB", "A B"}
// ip = ABC
// op = {"ABC", "A BC", "AB C", "A B C"}

#include <iostream>
#include <vector>
#include <string>

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

            string op1 = op + ip[0];
            string op2 = op + " " + ip[0];

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

int main(){
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    sol.solve(s.substr(1), s.substr(0, 1));
    sol.printPerms();
    return 0;
}
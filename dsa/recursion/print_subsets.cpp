// print subsets of a given string
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
        vector<string> strs; // use set for unique subsets / unique subsequences
    public:
        void subsets(string input, string output) {
            if(input.length() == 0) {
                strs.push_back(output);
                return;
            }

            subsets(input.substr(1), output); // without last char
            subsets(input.substr(1), output + input[0]);
            return;
        }

        void getSubsets() {
            sort(strs.begin(), strs.end());
            for(auto& ele : strs) {
                cout << "\"" << ele << "\"" << "\t";
            }
        }
};

int main() {
    Solution sol;
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    sol.subsets(s, "");
    sol.getSubsets();
}
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public: 
    string recrev_string(string s, int place){
        if(place == 0) {
            // converting to string because otherwise it will return a 'char' 
            return string(1, s[place]);
        }
        return string(1, s[place]) + recrev_string(s, place - 1);
    }
};

int main() {
    string str = "shreyans";
    Solution obj;
    cout << obj.recrev_string(str, str.length() - 1);
    return 0;
}
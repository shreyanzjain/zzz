#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // if t > s in len then not possible
        if(s.size() < t.size()) return "";

        // if both are the same size
        if(s.size() == t.size()) {
            unordered_map<char, int> sMap;
            unordered_map<char, int> tMap;

            for(int i = 0; i < s.size(); i++) {
                sMap[s[i]]++;
                tMap[t[i]]++;
            }

            if(sMap == tMap) return s;
        }

        // if t is smaller than s
        string sol = "";
        unordered_map<char, int> tMap;
        for(int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }

        int lo = 0;
        int hi = 0;

        // keep moving to the right till you find the first
        // char that is present in t / tMap
        while(lo < s.size() && tMap.find(s[lo]) == tMap.end()) {
            lo++;
            hi++;
        }
        
        // if lo exceeds the bounds then return empty string
        if(lo == s.size()) return sol;

        // if you find a char from t then we can start defining our
        // window that contains all the characters from t
        unordered_map<char, int> sMap;
        while(hi < s.size()) {
            if(tMap.find(s[hi]) != tMap.end()) {
                sMap[s[hi]]++;
            }

            if(sMap == tMap) {
                string window = s.substr(lo, (hi - lo) + 1);
                if(sol.size() != 0) {
                    if(window.size() < sol.size()) {
                        sol = window;
                        sMap[s[lo]]--;
                        do {
                            lo++;
                        } while(tMap.find(s[lo]) == tMap.end());

                        if(lo > s.size()) break;
                    }
                } else {
                    sol = window;
                    sMap[s[lo]]--;
                    do {
                        lo++;
                    } while (tMap.find(s[lo]) == tMap.end());
                    
                    if(lo > s.size()) break;
                }
            }
            hi++;
        }

        return sol;
    }

private:
    bool mapContainsMap(unordered_map<char, int> A, 
    unordered_map<char, int> B) {
        if(A == B) {
            return true;
        }

        unordered_map<char, int> :: iterator itr;
        for(itr = B.begin(); itr != B.end(); itr++) {
            if(A.find(itr->first) == A.end()) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}

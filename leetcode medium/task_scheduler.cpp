#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int answer = 0;
        unordered_map<char, int> value_counts;
        unordered_map<int, vector<char>> cooling_chars;
        // create a map of tasks and their occurences in the tasks vector, task => occurences
        for(int i = 0; i < tasks.size(); i++){
            value_counts[tasks[i]]++;
        }

        unordered_map<char, int> :: iterator itr;
        // int i = 0;
        // create a map of cooling times to tasks 
        // 0 => A B C ... (initially each task requires 0 cooling as it has not run)
        for(itr = value_counts.begin(); itr != value_counts.end(); itr++){
            cooling_chars[0].push_back(itr->first);
            // cout << cooling_chars[0][i] << "\t";
            // i++;
        }

        // create the rest of the empty cooling times
        // 1 => 
        // 2 => 
        // n => 
        // (inititally)
        for(int j = 1; j <= n; j++) {
            cooling_chars[j].push_back({});
        }

        while(!value_counts.empty()){
            // if there are any tasks eligible to run, then run the first
            if(cooling_chars[0].size() != 0) {
                char temp = cooling_chars[0][cooling_chars.size() - 1];
                cooling_chars[0].pop_back();
                value_counts[temp]--;
                // if there are no more of the SAME task remaining then remove it from the value counts map
                if(value_counts[temp] == 0) {
                    value_counts.erase(temp);
                }
                // add the task to the end
                cooling_chars[n].push_back(temp);
                answer++;
                cout << temp << "\t";
            }   else {
                answer++;
                cout << "idle" << "\t";
            }
        }
        return 0;
    }
};

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    Solution* sol;
    int answer = sol->leastInterval(tasks, n);
    printf("Solution: %d", answer);
}
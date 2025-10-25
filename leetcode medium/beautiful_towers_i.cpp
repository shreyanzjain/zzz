#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        vector<int> peakIndices = findPeakIndices(heights);
        vector<long long> sums;
        
        for(int j = 0; j < heights.size(); j++) {
            vector<int> temp = heights;
            long long sum = 0;
            int peakIndex = j;
            sum += heights[peakIndex];

            for(int i = peakIndex; i - 1 >= 0; i--) {
                if(heights[i - 1] > heights[i]) {
                    heights[i - 1] = heights[i];
                }
                
                sum += heights[i - 1];
            }
    
            for(int i = peakIndex; i + 1 < heights.size(); i++) {
                if(heights[i + 1] > heights[i]) {
                    heights[i + 1] = heights[i];
                }
    
                sum += heights[i + 1];
            }
    
            sums.push_back(sum);
            heights = temp;
        }

        return sums[findPeakIndex(sums)];
    }

    int findPeakIndex(vector<long long>& heights) {
        int peakIndex = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] > heights[peakIndex]) {
                peakIndex = i;
            }
        }

        return peakIndex;
    }

    vector<int> findPeakIndices(vector<int>& heights) {
        unordered_map<int, vector<int>> val_idx;
        for(int i = 0; i < heights.size(); i++) {
            val_idx[heights[i]].push_back(i);
        }

        int peakValue = -1;
        unordered_map<int, vector<int>> :: iterator itr;
        for(itr = val_idx.begin(); itr != val_idx.end(); itr++) {
            if(itr->first > peakValue) {
                peakValue = itr->first;
            }
        }

        return val_idx[peakValue];
    }
};

int main() {
    Solution sol;
    vector<int> heights = {5,5,3,2,6};
    cout << sol.maximumSumOfHeights(heights) << endl;
}

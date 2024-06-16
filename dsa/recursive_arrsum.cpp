#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> nums;

    Solution(vector<int>& vals) {
        nums = vals;
    }

    int rec_sum(int place) {
        if(place == nums.size()) {
            return 0;
        }
        return nums[place] + rec_sum(place + 1);
    }
};

int main() {
    vector<int> arr = {2,2,3,4,5,10};
    Solution obj(arr);
    cout << obj.rec_sum(0);
    return 0;
}
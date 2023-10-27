/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u_map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            u_map[nums[i]] = i; 
        }

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(u_map.find(diff) != u_map.end()) {

				// if the same element element adds up to target
				// eg. nums = [3,2,4] & target = 6
				// output = [0, 0]
                if (i == u_map[diff]) {
                    continue;
                }
                res.push_back(i);
                res.push_back(u_map[diff]);
                break;
            }
        }

        return res;
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int target;
    cin >> target;

    Solution *obj;
	vector<int> ans;
	ans = obj->twoSum(nums, target);
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}
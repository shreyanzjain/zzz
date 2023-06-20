/*
Hash Table
I would say this is a easy at best.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hash[100001] = {0};
        int curr;
        for(int i = 0; i < nums.size(); i++){
            if(hash[nums[i]] == 1){
                curr = nums[i];
                break;
            }
            hash[nums[i]]++;
        }

        return curr;
    }
};
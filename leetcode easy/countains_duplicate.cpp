class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> count_map;
        for(int i = 0; i < nums.size() ; i++)   {
            if(count_map.find(nums[i]) == count_map.end())  {
                count_map[nums[i]]++;
            }   else    {
                return true;
            }
        }
        return false;
    }
};

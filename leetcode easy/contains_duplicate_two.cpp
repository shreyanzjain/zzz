class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> index_map;

        for(int i = 0; i < nums.size(); i++)    {
            if(index_map.find(nums[i]) == index_map.end())  {
                index_map[nums[i]] = i;
            }   else    {
                if(abs(index_map[nums[i]] - i) <= k)    {
                    return true;
                }   else    {
                    index_map[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
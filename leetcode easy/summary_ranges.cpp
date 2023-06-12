/* Two Pointers */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0;
        int right = 1;

        while(left < nums.size())   {
            if(right < nums.size()
            && nums[right] == nums[right - 1] + 1)  {
                right++;
            }   else    {
                if(nums[left] == nums[right - 1])   {
                    ans.push_back(to_string(nums[left]));
                    left = right;
                    right++;
                }   else    {
                    ans.push_back(to_string(nums[left]) + "->" 
                    + to_string(nums[right - 1]));
                    left = right;
                    right++;
                }
            }
        }

        return ans;
    }
};
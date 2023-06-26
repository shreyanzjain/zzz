/*
If a number occurs more than twice,
set its value = 10001, third occurence onwards.
Finally sort the array.
O(nlogn)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int k = 0;

        while(right < nums.size()){
            if(nums[left] == nums[right]){
                if(right - left == 1){
                    right++;
                }   else{
                    nums[right] = 10001;
                    right++;
                    k++;
                }
            }   else{
                left = right;
                right++;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size() - k;
    }
};
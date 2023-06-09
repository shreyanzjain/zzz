/*
Basically to find the right pivot
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;

        while (left <= right)   {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[nums.size() - 1])   {
                left = mid + 1;
            }   else    {
                right = mid - 1;
            }
        }

        return nums[left];
    }
};
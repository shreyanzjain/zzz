/*
Find the pivot and then search one half of the array!
Binary Search
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left <= right)    {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[nums.size() - 1])   {
                left = mid + 1;
            }   else    {
                right = mid - 1;
            }
        }

        if(target > nums[nums.size() - 1])  {
            right = left - 1;
            left = 0;
            while(left <= right)    {
                mid = left + (right - left) / 2;
                if(nums[mid] == target)  {
                    index = mid;
                    break;
                }   else if(target > nums[mid]) {
                    left = mid + 1;
                }   else    {
                    right = mid - 1;
                }
            }
        }   else    {
            right = nums.size() - 1;
            while(left <= right)    {
                mid = left + (right - left) / 2;
                if(nums[mid] == target)  {
                    index = mid;
                    break;
                }   else if(target > nums[mid]) {
                    left = mid + 1;
                }   else    {
                    right = mid - 1;
                }
            }
        }

        return index;
    }
};
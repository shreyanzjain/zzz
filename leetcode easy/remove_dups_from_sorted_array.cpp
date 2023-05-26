class Solution {
public:
    void swap(int *p, int *q)    {
        int temp = *p;
        *p = *q;
        *q = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;

        while(right < nums.size()) {
            if(nums[left] > nums[right])    {
                break;
            }

            if(nums[left] == nums[right])   {
                right++;
            }   else    {
                swap(&nums[left + 1], &nums[right]);
                left++;
                right++;
            }
        }
        return left + 1;
    }
};
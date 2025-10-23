// write a sorting function to sort an array of integers based on the concepts of recursion
// follow along - aditya verma playlist
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
    public:
        vector<int> recursive_sort(vector<int>& nums) {
            if(nums.size() == 1) {
                return nums;
            }

            int temp_val = nums[nums.size() - 1]; // store the last element
            nums.pop_back(); // remove the last element

            recursive_sort(nums);
            recursive_insert(nums, temp_val);

            return nums;
        }

        vector<int> recursive_insert(vector<int>& nums, int value) {
            if((nums.size() == 0) || value >= nums[nums.size() - 1]) {
                nums.push_back(value);
                return nums;
            }

            int temp_val = nums[nums.size() - 1]; // store the last element
            nums.pop_back(); // remove the last element

            recursive_insert(nums, value);
            nums.push_back(temp_val);
            return nums;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 6, 1, 0, -11, 7, -12};
    
    cout<<"Before sort: ";
    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<"\t";
    } cout<<endl;
    
    sol.recursive_sort(nums);

    cout<<"After sort: ";
    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<"\t";
    } cout<<endl;

    return 0;
}

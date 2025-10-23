// sorting a stack with the minimum value on top

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    private:
    public:
        stack<int> recursive_sort(stack<int>& nums) {
            if(nums.size() == 1) {
                return nums;
            }

            int temp = nums.top();
            nums.pop();

            recursive_sort(nums);
            recursive_insert(nums, temp);
            
            return nums;
        }

        stack<int> recursive_insert(stack<int>& nums, int value) {
            if(nums.empty() || nums.top() >= value) {
                nums.push(value);
                return nums;
            }

            int temp = nums.top();
            nums.pop();
            recursive_insert(nums, value);
            nums.push(temp);
            return nums;
        }
};

int main() {
Solution sol;
    vector<int> vect = {3, 2, 6, 1, 0, -11, 7, -12};
    stack<int> nums;

    for(int ele : vect) {
        nums.push(ele);
    }
    
    sol.recursive_sort(nums);

    cout<<"After sort: ";
    for(int i = 0; i < vect.size(); i++) {
        cout<<nums.top()<<"\t";
        nums.pop();
    } cout<<endl;

    return 0;
}
#include <iostream>
#include <vector>

class Solution {
    public:
    std::vector<int> vals;
    Solution(std::vector<int>& nums) {
        vals = nums;
    }

    int max(int a, int b) {
        if((a == b) || (a > b)) {
            return a;
        }   else {
            return b;
        }
    }

    int recursive_max(int place) {
        if(place == vals.size() - 1) {
            return vals[place];
        }

        return max(vals[place], recursive_max(place + 1));
    }
};

int main() { 
    std::vector<int> nums = {1, 5, 4, 3, 10};
    Solution obj(nums);
    std:: cout << obj.recursive_max(0);
    return 0;
}
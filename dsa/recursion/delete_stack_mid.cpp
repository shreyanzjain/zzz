// delete the middle element of a stack using recursion
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    private:
    public:
    stack<int> delMiddle(stack<int>& st, int mid){
        if(st.size() == mid) {
            st.pop();
            return st;
        }

        int temp_val = st.top();
        st.pop();
        delMiddle(st, mid);
        st.push(temp_val);

        return st;
    }
};

int main() {
    Solution sol;
    vector<int> vect = {3, 2, 6, 1, 0, -11, 7, -12};
    stack<int> nums;
    int mid = vect.size() % 2 == 0
        ? vect.size() / 2
        : (vect.size() / 2) + 1;

    for(int ele : vect) {
        nums.push(ele);
    }
    
    sol.delMiddle(nums, mid);

    cout<<"After mid removal: ";
    for(int i = 0; i < vect.size() - 1; i++) {
        cout<<nums.top()<<"\t";
        nums.pop();
    } cout<<endl;
    return 0;
}
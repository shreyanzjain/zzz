// to reverse a stack using recursion
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    private: 
    public:
        stack<int> reverse(stack<int>& st) {
            if(st.empty()) {
                return st;
            }

            int top = st.top();
            st.pop();

            reverse(st);
            insert(st, top);
            return st;
        }

        stack<int> insert(stack<int>& st, int value) {
            if(st.empty()) {
                st.push(value);
                return st;
            }

            int top = st.top();
            st.pop();

            insert(st, value);
            st.push(top);
            return st;
        }
};

int main() {
    Solution sol;
    vector<int> vect = {3, 2, 6, 1, 0, -11, 7, -12};
    stack<int> nums;

    for(int ele : vect) {
        nums.push(ele);
    }
    
    stack<int> cpy = nums;
    sol.reverse(nums);

    cout<<"Before reverse: ";
    for(int i = 0; i < vect.size(); i++) {
        cout<<cpy.top()<<"\t";
        cpy.pop();
    } cout<<endl;

    cout<<"After reverse: ";
    for(int i = 0; i < vect.size(); i++) {
        cout<<nums.top()<<"\t";
        nums.pop();
    } cout<<endl;

    return 0;
}
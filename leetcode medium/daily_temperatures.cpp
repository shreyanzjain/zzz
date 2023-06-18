/*Stack
Keep storing index's onto the stack, 
as long as a higher temperature is not found,
once found - keep popping index's that have lower temps
than the current index, store the diff as the ans at that index
then finally push the current value and repeat the same process
till you reach the end of the array*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> index;
        for(int i = 0; i < ans.size(); i++){
            while(!index.empty() && temperatures[i] > 
            temperatures[index.top()]){
                ans[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return ans;
    }
};
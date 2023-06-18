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
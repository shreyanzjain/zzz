class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            if(prices[right] > prices[left]){
                int profit = prices[right] - prices[left];
                if(profit > max_profit){
                    max_profit = profit;
                }
            }   else    {
                left = right;
            }
            right++;
        }
        return max_profit;
    }
};
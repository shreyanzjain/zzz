/* as long as the tax bracket upper limit is 
less than income we basically calculate tax in parts
by multiplying the rate with the amount of money falling 
in that bracket. Once, the upper limit exceeds the income 
we calculate the difference by subtracting the previous 
threshold from the income. */

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int taxed_money = 0;
        double tax = 0.0;
        int i = 0;
        while(taxed_money < income) {
            int money_to_tax ;
            if(brackets[i][0] > income) {
                money_to_tax = income - taxed_money;
            }   else    {
                money_to_tax = brackets[i][0] - taxed_money;
            }
            int percent = brackets[i][1];
            tax += ((double)money_to_tax * (double)percent) / 100;
            taxed_money += money_to_tax;
            i++;
        }
        return tax;
    }
};
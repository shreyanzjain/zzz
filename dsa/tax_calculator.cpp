/*
Given tax slabs [3, 5, 9, 12, 15] -> the ith value is the upper limit for that slab in Unit Currency
and corresponding rates [0, 5, 10, 20, 30] -> the ith value is the corresponding tax rate in %

tax_slabs are given in a non-decreasing order
ith rate corresponds to the ith tax slab

Now, we have to calculate the tax given a salary X
0 <= X <= INT_MAX
*/

#include <iostream>
#include <vector>

using namespace std;

float calc_tax(vector<float>& tax_slabs, vector<float>& tax_rate, int salary){

    int sum_calculated = 0;
    float tax = 0;
    int i = 0;

    while(sum_calculated < salary){
        if(salary >= tax_slabs[i]){
            tax += ((float)(tax_slabs[i] - sum_calculated) * (float)tax_rate[i]) / 100.00;
            sum_calculated += (tax_slabs[i] - sum_calculated);
            i++;

            if(i > tax_slabs.size() - 1){
                // if we have exceeded the last tax slab while iterating
                // then the remaining amount is calculated based on the
                // last tax slab
                tax += ((float)(salary - sum_calculated) * (float)tax_rate[tax_rate.size() - 1]) / 100.00;
                sum_calculated = salary;
            }
        }   else{
            tax += ((float)(tax_slabs[i] - sum_calculated) * (float)tax_rate[i]) / 100.00;
            break;
        }
    }

    return tax;
}

int main(){
    vector<float> tax_slabs;
    vector<float> tax_rate;

    int no_of_slabs;
    cin >> no_of_slabs;
    float val;

    for(int i = 0; i < no_of_slabs; i++){
        cin >> val;
        tax_slabs.push_back(val);
    }

    for(int i = 0; i < no_of_slabs; i++){
        cin >> val;
        tax_rate.push_back(val);
    }

    int salary;
    cin >> salary;

    float tax;
    tax = calc_tax(tax_slabs, tax_rate, salary);

    cout << "Tax: " << tax << endl;
    return 0;
}
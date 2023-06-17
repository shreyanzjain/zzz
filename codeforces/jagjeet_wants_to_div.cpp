/*
https://codeforces.com/gym/447041/problem/A
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    vector<long long> nums;
    vector<int> ans;
    long long n;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> n;
        nums.push_back(n);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int ctr = 0;

        if (nums[i] == 1)
        {
            ans.push_back(0);
            continue;
        }

        while (nums[i] != 1)
        {
            if (nums[i] % 2 == 0)
            {
                nums[i] = nums[i] / 2;
                ctr++;
            }
            else if (nums[i] % 3 == 0)
            {
                nums[i] = (2 * nums[i]) / 3;
                ctr++;
            }
            else if (nums[i] % 5 == 0)
            {
                nums[i] = (4 * nums[i]) / 5;
                ctr++;
            }
            else
            {
                ctr = 0;
                break;
            }
        }

        if (ctr == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(ctr);
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
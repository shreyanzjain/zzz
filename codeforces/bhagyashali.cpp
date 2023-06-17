/*
https://codeforces.com/gym/448932/problem/A
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<string> strs;
    for (int i = 0; i < size; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    for (int i = 0; i < size; i++)
    {
        int first_half = 0;
        int second_half = 0;
        for (int j = 0; j < 6; j++)
        {
            if (j <= 2)
            {
                first_half += strs[i][j];
            }
            else
            {
                second_half += strs[i][j];
            }
        }

        if (first_half == second_half)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
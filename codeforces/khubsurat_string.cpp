/*
https://codeforces.com/gym/448932/problem/B
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replaceChar(char &x, char next_or_prev)
{
    if (next_or_prev == '?')
    {
        x = 'a';
    }
    else if (next_or_prev == 'a')
    {
        x = 'b';
    }
    else if (next_or_prev == 'b')
    {
        x = 'c';
    }
    else
    {
        x = 'a';
    }
}

void replaceChar(char &x, char next, char prev)
{
    if (next == '?')
    {
        replaceChar(x, prev);
    }
    else
    {
        if (prev == 'a' && next == 'b')
        {
            x = 'c';
        }
        else if (prev == 'a' && next == 'c')
        {
            x = 'b';
        }
        else if (prev == 'b' && next == 'a')
        {
            x = 'c';
        }
        else if (prev == 'b' && next == 'c')
        {
            x = 'a';
        }
        else if (prev == 'c' && next == 'a')
        {
            x = 'b';
        }
        else if (prev == 'c' && next == 'b')
        {
            x = 'a';
        }
        else if (prev == 'a' && next == 'a')
        {
            x = 'b';
        }
        else if (prev == 'b' && next == 'b')
        {
            x = 'c';
        }
        else if (prev == 'c' && next == 'c')
        {
            x = 'a';
        }
    }
}

void isKhubsurat(string str)
{
    int left = 0;
    int right = 1;
    while (right < str.length())
    {
        if (str[left] != '?' && str[left] == str[right])
        {
            cout << "-1" <<endl;
            return;
        }
        else
        {
            left++;
            right++;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '?')
        {
            if (i == 0)
            {
                if (i + 1 < str.length())
                {
                    replaceChar(str[i], str[i + 1]);
                }
                else
                {
                    str[i] = 'a';
                }
            }
            else if (i == str.length() - 1)
            {
                replaceChar(str[i], str[i - 1]);
            }
            else
            {
                replaceChar(str[i], str[i + 1], str[i - 1]);
            }
        }
    }
    cout << str << endl;
    return;
}

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
        isKhubsurat(strs[i]);
    }
    return 0;
}
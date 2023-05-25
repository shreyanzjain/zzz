#include <bits/stdc++.h>

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    pair<int, int> ans= {-1, -1};

    while(start <= end)  {
        mid = start + (end - start) / 2;
        if(arr[mid] == k)   {
            ans.first = mid;
            end = mid - 1;
        }   else    {
            if(k > arr[mid])    {
                start = mid + 1;
            }   else    {
                end = mid - 1;
            }
        }
    }

    start = 0;
    end = arr.size() - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == k)   {
            ans.second = mid;
            start = mid + 1;
        }   else    {
            if(k > arr[mid])    {
                start = mid + 1;
            }   else    {
                end = mid - 1;
            }
        }
    }

    return ans;

}
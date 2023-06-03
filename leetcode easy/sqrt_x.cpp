// Do not use, mid * mid because of integer overflow!!!

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x / 2;
        int mid;
        int sqrt_val = 1;

        if(x == 0 || x == 1)    {
            return x;
        }   else    {
            while(left <= right)    {
                mid = left + (right - left) / 2;
                if(mid == x / mid)  {
                    return mid;
                }   else if(mid > x / mid)  {
                    right = mid - 1;
                }   else    {
                    sqrt_val = mid;
                    left = mid + 1;
                }
            }
        }

        return sqrt_val;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& piles, int mid, int h){
        if(mid == 0){
            return false;
        }
        long int hours = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] <= mid){
                hours++;
            }   else{
                hours += ceil((double)piles[i] / mid);
            }
            if(hours > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 0;
        // max value of piles[i] becomes 'e'
        int e = -1;
        for(int i = 0; i < piles.size(); i++){
            e = max(e, piles[i]);
        }
        int mid;
        int min_hours = e;
        while(s <= e){
            mid = s + (e - s) / 2;
            if(isPossible(piles, mid, h)){
                min_hours = mid;
                e = mid - 1;
            }   else{
                s = mid + 1;
            }
        }

        return min_hours;
    }
};
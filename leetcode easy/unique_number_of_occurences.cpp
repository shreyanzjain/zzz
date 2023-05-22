class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> char_occur;
        unordered_map<int, int> occur_count;;

    for(int i = 0; i < arr.size(); i++){
        char_occur[arr[i]]++;
    }

    unordered_map<int, int> :: iterator itr;
    for(itr = char_occur.begin(); itr != char_occur.end(); itr++)  {
        if(occur_count.find(itr -> second) != occur_count.end())  {
            return false;
        }   else    {
            occur_count[itr -> second]++;
        }
    }

    return true;
    }
};
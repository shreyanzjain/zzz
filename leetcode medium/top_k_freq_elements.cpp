class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        for(int i = 0; i < nums.size(); i++){
            count_map[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> :: iterator itr;

        for(itr = count_map.begin(); itr != count_map.end(); itr++) {
            bucket[itr -> second].push_back(itr->first);
        }

        vector<int> result;
        for(int i = nums.size(); i >= 0; i--)   {
            if(result.size() >= k)  {
                break;
            }   

            if(!bucket[i].empty())  {
                result.insert(result.end(), 
                bucket[i].begin(), bucket[i].end());
            }
        }
        return result;
    }
};
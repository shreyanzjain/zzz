/* MAP 
use a hash_map and count the occurences of each row, 
an unordered_map does not work because of operator issues. 
then loop through the columns and check 
the map if any of the keys match a column, 
if so add the occurence of the key to the answer
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int total_hits = 0;
        map<vector<int>, int> unique_rows;
        vector<int> col;

        for(int i = 0; i < grid.size(); i++)    {
            unique_rows[grid[i]]++;
        }

        for(int i = 0; i < grid[0].size(); i++) {
            for(int j = 0; j < grid.size(); j++)    {
                col.push_back(grid[j][i]);
            }
            if(unique_rows.find(col) != unique_rows.end())  {
                total_hits += unique_rows[col];
                col.erase(col.begin(), col.end());
            }   else    {
                col.erase(col.begin(), col.end());
            }
        }
        return total_hits;
    }
};
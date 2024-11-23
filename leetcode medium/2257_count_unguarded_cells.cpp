/** 0 is a unguarded cell
*  1 is a guarded cell
*  2 is a guard
*  3 is a wall
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {

private:

    void createWallMap(map<vector<int>, int>& wall_map, vector<vector<int>> walls) {
        for(int i = 0; i < walls.size(); i++) {
            wall_map[walls[i]]++;
        }
    }

    void placeGuards(vector<vector<int>>& terrain, vector<vector<int>>& guards) {
        for(int i = 0; i < guards.size(); i++) {
            terrain[guards[i][0]][guards[i][1]] = 2;
        }
    }

    int deduceTerrainState(vector<vector<int>>& terrain, 
                            vector<vector<int>>& guards,
                            map<vector<int>, int>& wall_map) {
        int guarded = 0;

        for(int i = 0; i < guards.size(); i++) {
            int guarded_ = guardCells(guards[i][0], guards[i][1], wall_map, terrain);
            guarded += guarded_;
        }

        return guarded;
    }

    int guardCells(int row, int col, map<vector<int>, int>& wall_map,
                    vector<vector<int>>& terrain) {
        int up = guardUpwards(row, col, wall_map, terrain);
        int down = guardDownwards(row, col, wall_map, terrain);
        int right = guardRightwards(row, col, wall_map, terrain);
        int left = guardLeftwards(row, col, wall_map, terrain);

        return up + down + left + right;
    }

    int guardUpwards(int row, int col, map<vector<int>, int>& wall_map,
                    vector<vector<int>>& terrain) {
        int ctr = 0;
        row--; // start from one step above the guard
        while(row >= 0) {
            vector<int> coords = { row, col };
            if(terrain[row][col] == 2) {
                break;
            }   else if(wall_map.find(coords) != wall_map.end()){
                terrain[row][col] = 3;
                break;
            } else {
                mkUnguarded(row, col, terrain, ctr);
            }
            row--;
        }

        return ctr;
    }

    int guardDownwards(int row, int col, map<vector<int>, int>& wall_map,
                    vector<vector<int>>& terrain) {
        int ctr = 0;
        row++; // start from one step below the guard
        while(row <= terrain.size() - 1) {
            vector<int> coords = { row, col };
            if(terrain[row][col] == 2) {
                break;
            }   else if(wall_map.find(coords) != wall_map.end()){
                terrain[row][col] = 3;
                break;
            } else {
                mkUnguarded(row, col, terrain, ctr);
            }
            row++;
        }

        return ctr;
    }

    int guardRightwards(int row, int col, map<vector<int>, int>& wall_map,
                    vector<vector<int>>& terrain) {
        int ctr = 0;
        col++; // start from one step to the right of the guard
        while(col <= terrain[0].size() - 1) {
            vector<int> coords = { row, col };
            if(terrain[row][col] == 2) {
                break;
            }   else if(wall_map.find(coords) != wall_map.end()){
                terrain[row][col] = 3;
                break;
            } else {
                mkUnguarded(row, col, terrain, ctr);
            }
            col++;
        }

        return ctr;
    }

    int guardLeftwards(int row, int col, map<vector<int>, int>& wall_map,
                    vector<vector<int>>& terrain) {
        int ctr = 0;
        col--; // start from one step to the left of the guard
        while(col >= 0) {
            vector<int> coords = { row, col };
            if(terrain[row][col] == 2) {
                break;
            }   else if(wall_map.find(coords) != wall_map.end()){
                terrain[row][col] = 3;
                break;
            } else {
                mkUnguarded(row, col, terrain, ctr);
            }
            col--;
        }

        return ctr;
    }

    int mkUnguarded(int row, int col, vector<vector<int>>& terrain, int& ctr) {
        if(terrain[row][col] == 1) {
            return ctr;
        }   else {
            terrain[row][col] = 1;
            ctr++;
            return ctr;
        }
    }


public:

    int countUnguarded(int m, int n, 
                        vector<vector<int>>& guards, 
                        vector<vector<int>>& walls) {
        
        vector<vector<int>> terrain(m, vector<int>(n));
        map<vector<int>, int> wall_map;

        createWallMap(wall_map, walls);
        placeGuards(terrain, guards);
        int guardedCount = deduceTerrainState(terrain, guards, wall_map);
        int unguardedCount = (m * n) - guardedCount - guards.size() - walls.size();

        return unguardedCount;
    }
};

int main() { 
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    int m = 4;
    int n = 6;

    Solution obj;
    obj.countUnguarded(m , n, guards, walls);
}
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size() - 1;
        int x = 0;
        int y = 0;
        int sum = 0;

        while(x <= size)    {
            sum += mat[x][y];
            x++;
            y++;
        }

        x = 0;
        y = 0;
        while(x <= size)    {
            sum += mat[x][size - y];
            x++;
            y++;
        }

        if(size % 2 == 0)   {
            sum = sum - mat[size/2][size/2];
        }
        
        return sum;
    }
};
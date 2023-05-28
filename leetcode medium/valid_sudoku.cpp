class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int count = 9;
        bool row[count][count] = {false};
        bool col[count][count] = {false};
        bool sqr[count][count] = {false};

        for(int r = 0; r < count; r++)  {
            for(int c = 0; c < count; c++)  {
                if(board[r][c] == '.'){
                    continue;
                }

                int index = board[r][c] - '0' - 1;
                int area = ((r/3) * 3) + c/3;

                if(row[r][index] || col[c][index] || sqr[area][index]) {
                    return false;
                }

                row[r][index] = true;
                col[c][index] = true;
                sqr[area][index] = true;
            }
        }

        return true;
    }
};
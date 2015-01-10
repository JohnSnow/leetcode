#include <cstring>
#include <vector>

using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[10] = {0};
        int col[9][10] = {{0}};
        int sub[9][10] = {{0}};

        for(int i=0; i < 9; i++)
        {
            memset(row, 0 , sizeof(row));
            for(int j=0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if(!isValid(row, num) || 
                        !isValid(col[j], num) ||
                        !isValid(sub[i/3 * 3 + j/3], num))
                    {
                        return false;
                    }
                }
            }
        }
        return true;

    }

    bool isValid(int vec[], int a)
    {
        if(vec[a] == 1) return false;
        vec[a] = 1;
        return true;
    }
};

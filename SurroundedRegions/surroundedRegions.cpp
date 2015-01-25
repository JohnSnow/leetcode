#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;

class Solution {
public:
    void solve(vector<vector<char> > &board) {

        if(board.size() < 3 || board[0].size() < 3) return;

        std::queue<std::pair<int, int> > Q;

        size_t row = board.size();
        size_t col = board[0].size();

        vector<vector<bool> > mark(row, vector<bool>(col, false));

        for(size_t i = 0; i < row; i++) {
            if(board[i][0] == 'O') Q.push(pair<int, int> (i, 0));
            if(board[i][col - 1] == 'O') Q.push(pair<int,int>(i, col - 1));
        }

        for(size_t i=1; i< col - 1; i++) {
            if(board[0][i] == 'O') Q.push(pair<int,int>(0, i));
            if(board[row - 1][i] == 'O') Q.push(pair<int,int>(row -1, i));
        }

        while(!Q.empty()) {
            pair<int,int> elem = Q.front();
            Q.pop();
            size_t x = elem.first;
            size_t y = elem.second;

            mark[x][y] = true;
            board[x][y] = 'Y';

            if(x > 0 && !mark[x-1][y] && board[x-1][y] == 'O') Q.push(pair<int,int>(x-1, y));
            if(x < row - 1 && !mark[x+1][y] && board[x+1][y] == 'O') Q.push(pair<int,int>(x+1, y));
            if(y>0 && !mark[x][y-1] && board[x][y-1] == 'O') Q.push(pair<int, int>(x, y-1));
            if(y< col -1 && !mark[x][y+1] && board[x][y+1] == 'O') Q.push(pair<int, int>(x, y+1));
        }

        for(size_t i=0; i< row; i++){
            for(size_t j =0; j< col; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char> > board{
    {'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X'}};

    Solution * sl = new Solution();
    sl->solve(board);

    int row = board.size();
    int col = board[0].size();
    for(int i=0; i< row; i++) {
        for(int j =0; j<col; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

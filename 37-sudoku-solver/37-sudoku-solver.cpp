class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& board,char c){
        for(int k = 0;k<9;k++){
            if(board[i][k]==c)return false;
            if(board[k][j]==c)return false;
        }
        int ci = 3*(i/3),cj = 3*(j/3);
        for(int ki = 0;ki<3;ki++){
            for(int kj = 0;kj<3;kj++){
                if(board[ci+ki][cj+kj]==c)return false;
            
            }
        }
        return true;
    }
    bool solve(int i, int j, vector<vector<char>> &board){
        if(i==9)return true;
        if(j==9)return solve(i+1, 0, board);
        if(board[i][j]!='.')return solve(i, j+1, board);
        for(char c = '1';c<='9';c++){
            if(valid(i,j, board, c)){
                board[i][j] = c;
                if(solve(i, j+1, board))return true;
                board[i][j] = '.';
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};
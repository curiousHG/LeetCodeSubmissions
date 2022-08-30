class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& gr){
        if(i<0 || j<0 || i>=gr.size() || j>=gr[0].size()|| gr[i][j]=='X' || gr[i][j]=='d')return;
        gr[i][j] = 'd';
        dfs(i+1, j, gr);
        dfs(i-1, j, gr);
        dfs(i, j-1, gr);
        dfs(i, j+1, gr);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(),m = board[0].size();
        for(int i = 0;i<n;i++){
            dfs(i, 0,board);
            dfs(i, m-1, board);
        }
        for(int j = 0;j<m;j++){
            dfs(0,j, board);
            dfs(n-1, j, board);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]=='d')board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
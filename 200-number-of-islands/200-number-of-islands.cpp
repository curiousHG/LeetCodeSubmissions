class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        // vector<vector<bool>> vis(n,vector<int>(m,false));
        int c = 0;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    bfs(i,j, grid,n,m);
                }
            }
        }
        return c;
    }
    void bfs(int i,int j,vector<vector<char>>& grid,int n,int m){
        if(i<0 || i>=n || j<0||j>=m)return;
        if(grid[i][j]!='1'){
            return;
        }else{
            grid[i][j]='2';
        }
        bfs(i+1,j,grid,n,m);
        bfs(i-1,j,grid,n,m);
        bfs(i,j-1,grid,n,m);
        bfs(i,j+1,grid,n,m);
    }
};
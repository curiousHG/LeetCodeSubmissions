class Solution {
public:
    void dfs(int i, int j,int t, vector<vector<int>>& grid,vector<vector<int>> &time){
        if(i<0 ||j<0|| i>=grid.size()|| j>=grid[0].size()||grid[i][j]==0 || (grid[i][j]==2 && time[i][j]==0))return;
        int k = 0;
        if(grid[i][j]==2){
            time[i][j] = 0;
            k= 1;
        }else{
            if(time[i][j]<=t)return;
            time[i][j] = t;
            k = t+1;
        }
        dfs(i+1, j, k, grid, time);
        dfs(i-1, j, k, grid, time);
        dfs(i, j-1, k, grid, time);
        dfs(i, j+1, k, grid, time);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2 && time[i][j]!=0){
                    dfs(i,j,0,grid,time);
                }
            }
        }
        int mini = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0)continue;
                if(grid[i][j]==1 && time[i][j]==INT_MAX)return -1;
                mini = max(mini, time[i][j]);
                
            }
        }
        return mini;
    }
};
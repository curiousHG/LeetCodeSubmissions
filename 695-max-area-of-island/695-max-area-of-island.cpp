class Solution {
public:
    int maxi = 0;
    int area = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    area = 0;
                    solve(grid, i, j,n,m);
                }
            }
        }
        return maxi;
    }
    void solve(vector<vector<int>>& grid,int i,int j,int n, int m){
        if(i<0 || i>=n||j<0 ||j>=m)return;
        if(grid[i][j]!=1)return;
        grid[i][j]=0;
        area++;
        maxi = max(maxi, area);
        solve(grid, i+1, j, n, m);
        solve(grid, i-1, j, n, m);
        solve(grid, i, j+1, n, m);
        solve(grid, i, j-1, n, m);
        
    }
};
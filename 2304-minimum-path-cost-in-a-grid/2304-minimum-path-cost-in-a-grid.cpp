class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    int dp(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& mC){
        if(i==0)return grid[i][j];
        if(memo[i][j]!=-1)return memo[i][j];
        int val = INT_MAX;
        for(int k = 0;k<n;k++){
            val = min(val, grid[i][j]+dp(i-1, k, grid, mC)+mC[grid[i-1][k]][j]);
        }
        memo[i][j] = val;
        return val;
        
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m= grid.size(),n = grid[0].size();
        memo.resize(m, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int k = 0;k<n;k++){
            ans = min(ans, dp(m-1,k,grid,moveCost));
        }
        return ans;
        
    }
};
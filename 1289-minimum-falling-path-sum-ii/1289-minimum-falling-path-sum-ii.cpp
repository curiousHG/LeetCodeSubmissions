class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i, int j,int n,vector<vector<int>>& grid){
        if(j<0 || j>=n)return INT_MAX;
        if(i==n-1)return grid[i][j];
        if(memo[i][j]!=-1)return memo[i][j];
        int low = INT_MAX;
        for(int k = 0;k<j;k++){
            low = min(low,dp(i+1, k, n, grid));
        }
        for(int k = j+1;k<n;k++){
            low = min(low,dp(i+1, k, n, grid));
        }
        return memo[i][j]=grid[i][j]+low;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        memo.resize(n, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans, dp(0,i,n,grid));
        }
        return ans;
    }
};
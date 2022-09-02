class Solution {
public:
    vector<vector<int>> memo;
    int n, m;
    int dp(int i, int j,vector<vector<int>>& du){
        if(i>=n || j>=m)return INT_MAX;
        if(memo[i][j]!=-1)return memo[i][j];
        int val = min(dp(i+1,j,du), dp(i, j+1,du));
        if(du[i][j]>=0)val = max(val-du[i][j], 1);
        else val-=du[i][j];
        return memo[i][j] = val;
        
        
    }
    int calculateMinimumHP(vector<vector<int>>& du) {
        int a = du.size(),b = du[0].size();
        n = a;m = b;
        // vector<vector<int>> dp(n,vector<int>>(m));
        memo.resize(n, vector<int>(m,-1));
        if(du[n-1][m-1]>=0)memo[n-1][m-1] = 1;
        else memo[n-1][m-1] = 1-du[n-1][m-1];
        return dp(0,0,du);
                
    }
};
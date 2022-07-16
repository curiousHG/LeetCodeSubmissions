class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(),m = mat[0].size(),val;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(mat[i][j]=='0')continue;
                if(i==0 || j==0){
                    dp[i][j]=1;
                    maxi = max(maxi, dp[i][j]);
                    continue;
                }
                val = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                if(val==-1)dp[i][j]=1;
                else dp[i][j] = 1+val;
                maxi = max(maxi, dp[i][j]);
                
                
            }
        }
        return maxi*maxi;
        
    }
};
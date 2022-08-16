class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+2, vector<int>(3,0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        for(int i = 2;i<=n;i++){
            dp[i][0] = ((dp[i-1][0]%mod+dp[i-2][0]%mod)%mod+(dp[i-1][1]%mod+dp[i-1][2]%mod)%mod)%mod;
            dp[i][1] = (dp[i-2][0]%mod+dp[i-1][1]%mod)%mod;
            dp[i][2] = (dp[i-2][0]%mod+dp[i-1][2]%mod)%mod;
        }
        
        return dp[n][0];
    }
};
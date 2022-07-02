class Solution {
public:
    int countVowelPermutation(int n) {
        int dp[n+1][5];
        int mod = 1e9+7;
        for(int i = 0;i<5;i++){
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        int ans =0;
        for(int i = 2;i<=n;i++){
            dp[i][0] = ((long)dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
            dp[i][1] = ((long)dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2] = ((long)dp[i-1][1]+dp[i-1][3])%mod;
            dp[i][3] = ((long)dp[i-1][2])%mod;
            dp[i][4] = ((long)dp[i-1][2]+dp[i-1][3])%mod;
        }
        for(int i = 0;i<5;i++){
            ans=((long)ans+dp[n][i])%mod;
        }
        return ans;
        
        
        
    }
};
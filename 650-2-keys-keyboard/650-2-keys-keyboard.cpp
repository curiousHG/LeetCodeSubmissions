class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 2;j*i<=n;j++){
                dp[j*i] = min(dp[j*i],dp[i]+(j));
            }
            // cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};
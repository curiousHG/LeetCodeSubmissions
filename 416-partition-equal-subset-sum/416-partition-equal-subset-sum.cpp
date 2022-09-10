class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,n = nums.size();
        for(int i= 0;i<n;i++)sum+=nums[i];
        if(sum%2)return false;
        int m = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0;i<=n;i++)dp[i][0] = 1;
        for(int i= 1;i<=n;i++){
            for(int j = 0;j<=m;j++){
                dp[i][j] = dp[i-1][j];
                if(i>0 && j>=nums[i-1])dp[i][j] = max(dp[i][j],dp[i-1][j-nums[i-1]]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][m];
        
    }
};
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n)+1;
        vector<int> dp(m*m+1,0);

        for(int i= 1;i<=n;i++){
            int mini = INT_MAX;
            for(int j = 1;j<=m;j++){
                int sq= j*j;
                if(sq>i)break;
                mini = min(mini, dp[i-sq]+1);
                if(mini==1)break;
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};
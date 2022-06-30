class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n)+1;
        vector<int> sq;
        vector<int> dp(m*m+1,0);
        for(int i = 1;i<=m;i++){
            sq.push_back(i*i);
        }
        for(int i= 1;i<=n;i++){
            int mini = INT_MAX;
            for(int j = 0;j<sq.size();j++){
                if(sq[j]>i)break;
                mini = min(mini, dp[i-sq[j]]+1);
                if(mini==1)break;
                
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};
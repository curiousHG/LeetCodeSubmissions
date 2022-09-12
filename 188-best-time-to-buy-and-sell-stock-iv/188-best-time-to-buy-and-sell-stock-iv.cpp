class Solution {
public:
    vector<vector<int>> memo;
    int dp(int k, int i,vector<int>& prices){
        if(k==0 || i==0)return 0;
        // cout<<k<<" "<<i<<endl;
        if(memo[k][i]!=-1)return memo[k][i];
        
        int val = -INT_MAX;
        for(int j = 0;j<=i;j++){
            val = max(val, dp(k-1,j,prices)+prices[i]-prices[j]);

        }
        val = max(val, dp(k,i-1,prices));
        return memo[k][i] = val;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1 || k==0)return 0;
        memo.resize(k+1, vector<int>(n,-1));
        return max(0,dp(k, n-1,prices));
    }
};
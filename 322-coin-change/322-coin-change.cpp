class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i = 1;i<=amount;i++){
            int mini = INT_MAX;
            for(int j = 0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=-1){
                    mini = min(mini, dp[i-coins[j]]+1);
                }
                if(i-coins[j]<0)break;
            }
            if(mini!=INT_MAX)dp[i] = mini;
        }
        return dp[amount];
        
        
    }
};
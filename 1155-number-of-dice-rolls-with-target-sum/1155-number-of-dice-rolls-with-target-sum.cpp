class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> memo;
    int dp(int i, int k, int t){
        if(i==0 || t<i)return 0;
        if(i==1 && t<=k)return 1;
        if(t==i)return 1;
        if(memo[i][t]!=-1)return memo[i][t];
        long val = 0;
        for(int l = 1;l<=k;l++){
            val = (val + dp(i-1,k,t-l))%mod;
        }
        return memo[i][t] = val;
        
        
    }
    int numRollsToTarget(int n, int k, int t) {
        memo.resize(n+1, vector<int>(t+1,-1));
        return dp(n, k, t);
        
    }
};
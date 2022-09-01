class Solution {
public:
    vector<int> memo;   
    int dp(int n, vector<int>& cost){
        if(n==0 || n==1)return 0;
        if(memo[n]!=-1)return memo[n];
        return memo[n] = min(dp(n-1,cost)+cost[n-1], dp(n-2,cost)+cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        memo.resize(n+1, -1);
        return dp(n, cost);
    }
};
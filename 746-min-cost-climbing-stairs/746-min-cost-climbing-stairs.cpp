class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> mins(n+1,0);
        mins[0] = 0;
        mins[1] = 0;
        for(int i = 2;i<=n;i++){
            mins[i] = min(mins[i-1]+cost[i-1],mins[i-2]+cost[i-2]);
        }
        return mins[n];
    }
};
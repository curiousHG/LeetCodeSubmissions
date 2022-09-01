class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i, int j, vector<vector<int>>& oG){
        if(i==0 && j==0 && oG[i][j]==0)return 1;
        if(i<0 || j<0)return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        if(oG[i][j]==1)return 0;
        return memo[i][j] = dp(i-1,j,oG)+dp(i,j-1,oG);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int n = oG.size(),m = oG[0].size();
        memo.resize(n, vector<int>(m, -1));
        return dp(n-1, m-1,oG);
    }
};
class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i, int j,int n,vector<vector<int>>& mat){
        if(j<0 || j>=n)return INT_MAX;
        if(i==n-1)return mat[i][j];
        if(memo[i][j]!=-1)return memo[i][j];
        int low = INT_MAX;
        for(int k = -1;k<=1;k++){
            low = min(low, dp(i+1,j-k,n,mat));
        }
        return memo[i][j] = mat[i][j]+low;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        memo.resize(n, vector<int>(m,-1));
        int mini = INT_MAX;
        for(int j = 0;j<m;j++){
            mini = min(mini, dp(0,j,n,mat));
        }
        return mini;
        
    }
};
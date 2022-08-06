class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0||j==0){
                    if(mat[i][j]){
                        
                        dp[i+1][j+1]=1;
                    }
                }else if(mat[i][j]){
                    dp[i+1][j+1] = 1+min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
                }
                ans+=dp[i+1][j+1];
                
            }
        }
        return ans;
        
    }
};
/*
0 0 0 0 0
0 0 1 1 1
0 1 1 2 2
0 0 1 2 3
*/
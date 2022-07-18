class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 && j==0)dp[i][j] = mat[i][j];
                else if(i==0)dp[i][j] = mat[i][j]+dp[i][j-1];
                else if(j==0)dp[i][j] = mat[i][j]+dp[i-1][j];
                else dp[i][j] = mat[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
            }
        }
        int val,ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int li = i;li<n;li++){
                    for(int lj = j;lj<m;lj++){
                        val = dp[li][lj];
                        if(li==i && lj==j);
                        else if(li==i)val-=dp[i][j];
                        else if(lj==j)val-=dp[i][j];
                        else val +=dp[i][j]-dp[li][j]-dp[i][lj];
                        
                        if(val==t)ans++;
                        
                    }
                }
            }
        }
        return ans;
        
    }
};
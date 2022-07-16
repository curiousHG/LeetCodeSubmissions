class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(5,1));
        for(int i = 1;i<n;i++){
            for(int j = 0;j<5;j++){
                dp[i][j]= 0;
                for(int k = 0;k<=j;k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        int ans = 0;
        for(int i= 0;i<5;i++){
            ans+=dp[n-1][i];
        }
        return ans;
        
    }
};
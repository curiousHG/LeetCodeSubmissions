class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(),maxi = 0;
        vector<int> dp(n);
        for(int i = 1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = (i>1?dp[i-2]:0)+2;
                }else{
                    int val = i-dp[i-1];
                    if(val>0){
                        if(s[val-1]=='(')
                        dp[i] = dp[i-1]+((val>=2)?dp[val-2]:0)+2;
                    }
                }
                maxi = max(maxi, dp[i]);
            }
        }
        if(n==0)return 0;
        return maxi;

    }
};
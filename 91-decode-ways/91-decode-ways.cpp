class Solution {
public:
    int ans = 0;
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i = 0;i<n;i++){
            if(s[i]!='0'){
                dp[i+1]+=dp[i];
            }
            if(i==0)continue;
            int p = (s[i-1]-'0')*10+(s[i]-'0');
            if(p<27 &&s[i-1]!='0' )dp[i+1]+=dp[i-1];
        }
        return dp[n];
        
    }
    
};
class Solution {
public:

    bool wordBreak(string s, vector<string>& w) {
        unordered_set<string> ws(w.begin(),w.end());
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1;i<=n;i++){
            for(int j = i-1;j>-1;j--){
                if(dp[j]){
                    string temp = s.substr(j, i-j);
                    if(ws.find(temp)!=ws.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
        
    }
};
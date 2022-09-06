class Solution {
public:
    vector<vector<int>> memo;
    bool dp(int i , int j, string s, string p){
        // cout<<i<<" "<<j<<"->"<<s.substr(i)<<" "<<p.substr(j)<<endl;
        // cout<<i<<" "<<j<<endl;
        
        if(j==p.length())return memo[i][j] = i==s.length();
        // cout<<i<<" "<<j<<endl;
        if(memo[i][j]!=-1)return memo[i][j];
        bool c = i<s.length() &&(s[i]==p[j] || p[j]=='.');
        if(p.length()-j>1 && p[j+1]=='*'){
            return memo[i][j] = dp(i, j+2,s, p)||(c && dp(i+1, j, s, p));
        }else{
            return memo[i][j] = c && dp(i+1, j+1, s, p);
        }
        
    }
    bool isMatch(string s, string p) {
        memo.resize(s.length()+1, vector<int>(p.length()+1,-1));
        return dp(0,0,s,p);
    }
};
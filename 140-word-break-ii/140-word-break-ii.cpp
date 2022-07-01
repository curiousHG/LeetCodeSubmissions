class Solution {
public:
    unordered_set<string> dic;
    vector<string> ans;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string s:wordDict){
            dic.insert(s);
        }
        solve("",0,s);
        // cout<<s.substr(0,1);
        return ans;
        
    }
    void solve(string cur, int i, string s){
        // cout<<cur<<" "<<i<<endl;
        if(i==s.length()){
            string sol = cur.substr(0,cur.length()-1);
            ans.push_back(sol);
        }else{
            for(int k = 1;k<=s.length()-i;k++){
                string temp = s.substr(i,k);
                // cout<<temp<<endl;
                if(dic.find(temp)!=dic.end()){
                    string f = cur+temp+" ";
                    // cout<<k+1<<endl;
                    solve(f,k+i,s);
                }
            }
        }
        
    }
};
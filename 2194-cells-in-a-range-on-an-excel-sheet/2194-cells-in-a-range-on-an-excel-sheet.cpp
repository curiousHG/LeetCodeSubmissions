class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for(char i = s[0];i<=s[3];i++){
            for(char j = s[1];j<=s[4];j++){
                char a = i,b = j;
                // cout<<a<<" "<<b<<endl;
                string t(1,a);
                t+=b;
                // cout<<t<<endl;
                ans.push_back(t);
            }
        }
        return ans;
        
    }
};
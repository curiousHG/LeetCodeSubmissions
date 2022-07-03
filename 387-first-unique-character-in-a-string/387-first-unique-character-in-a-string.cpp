class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> co(26,-1);
        for(int i = 0;i<s.length();i++){
            if(co[s[i]-'a']==-1){
                co[s[i]-'a'] = i;
            }else if(co[s[i]-'a']==-2){
                continue;
            }else{
                co[s[i]-'a'] = -2;
            }
        }
        int mini = s.length();
        for(int i = 0;i<26;i++){
            if(co[i]>=0)
            mini = min(mini, co[i]);
        }
        if(mini==s.length())return -1;
        else return mini;
        
    }
};
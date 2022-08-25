class Solution {
public:
    bool canConstruct(string rN, string m) {
        vector<int> v(26,0);
        for(char c:m)v[c-'a']++;
        for(char c:rN){
            if(v[c-'a']==0)return false;
            v[c-'a']--;
        }
        return true;
    }
};
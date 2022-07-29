class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<int> c = pat(pattern),d;
        for(string b:words){
            if(pattern.length()!=b.length())continue;
            d = pat(b);
            bool f =true;
            for(int i = 0;i<d.size();i++){
                if(c[i]!=d[i]){
                    f = false;
                    break;
                }
            }
            if(f)ans.push_back(b);
        }
        return ans;
        
    }
    vector<int> pat(string a){
        unordered_map<char,int> mp;
        vector<int> p;
        int k= 0;
        for(char c:a){
            if(mp.find(c)==mp.end()){
                mp[c] = k;
                k++;
            }
            p.push_back(mp[c]);
        }
        return p;
    }
};
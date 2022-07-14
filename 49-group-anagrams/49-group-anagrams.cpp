class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        string t;
        for(int i = 0;i<strs.size();i++){
            t = strs[i];
            sort(t.begin(),t.end());
            if(m.find(t)==m.end()){
                m[t] = vector<string>();
            }
            m[t].push_back(strs[i]);
        }
        for(const auto &it:m){
            ans.push_back(it.second);
        }
        return ans;
        
        
    }
};
class Solution {
public:
    unordered_map<string, vector<string>> pair;
    unordered_set<string> poss;
    unordered_set<string> st;
    void dfs(string item){
        if(poss.find(item)!=poss.end())return;
        if(pair.find(item)==pair.end())return;
        bool ip = true;
        for(string s:pair[item]){
            if(st.find(s)!=st.end()){
                ip = false;
                break;
            }
            st.insert(s);
            dfs(s);
            st.erase(s);
            if(poss.find(s)==poss.end()){
                ip = false;
                break;
            }
            
        }
        if(ip)poss.insert(item);
    }
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        int n = rec.size(),m = sup.size();
        for(int i = 0;i<n;i++){
            if(pair.find(rec[i])==pair.end()){
                vector<string> temp;
                pair[rec[i]] = temp;
            }
            for(string s:ing[i])pair[rec[i]].push_back(s);
        }
        for(int i = 0;i<m;i++)poss.insert(sup[i]);
        vector<string> ans;
        for(string s:rec){
            dfs(s);
            if(poss.find(s)!=poss.end())ans.push_back(s);
        }
        return ans;
    }
};
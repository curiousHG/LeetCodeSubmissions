class Solution {
public:
    void dfs(string item,map<string, vector<string>> &pair,map<string, bool> &poss, unordered_set<string> &st){
        if(poss.find(item)!=poss.end())return;
        if(pair.find(item)==pair.end())return;
        bool ip = true;
        for(string s:pair[item]){
            if(st.find(s)!=st.end()){
                ip = false;
                break;
            }
            st.insert(s);
            dfs(s, pair, poss,st);
            st.erase(s);
            // cout<<item<<endl;
            // cout<<s<<"|";
            if(poss.find(s)==poss.end()){
                // cout<<"Break->"<<s<<endl;
                ip = false;
                break;
            }
            
        }
        // cout<<endl;
        if(ip){
            poss[item] = true;
        }
    }
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        map<string, vector<string>> pair;
        map<string,bool> poss;
        unordered_set<string> st;
        int n = rec.size(),m = sup.size();
        for(int i = 0;i<n;i++){
            if(pair.find(rec[i])==pair.end()){
                vector<string> temp;
                pair[rec[i]] = temp;
            }
            for(string s:ing[i])pair[rec[i]].push_back(s);
        }
        for(int i = 0;i<m;i++)poss[sup[i]] = true;
        vector<string> ans;
        for(string s:rec){
            dfs(s, pair, poss,st);
            if(poss.find(s)!=poss.end())ans.push_back(s);
        }
        return ans;
    }
};
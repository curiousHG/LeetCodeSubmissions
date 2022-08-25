class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> done(n,true);
        unordered_map<int,vector<int>> g;
        for(auto &p:pre){
            if(g.find(p[0])==g.end()){
                g[p[0]] = vector<int>();
            }
            g[p[0]].push_back(p[1]);
            done[p[0]] = false;
        }
        
        for(int i = 0;i<n;i++){
            unordered_set<int> ss;
            if(!dfs(i,ss,done,g))return false;
        }
        return true;
        
    }
    bool dfs(int i,unordered_set<int> &ss,vector<bool> &done,unordered_map<int,vector<int>> &g){
        bool l = ss.find(i)!=ss.end();
        if(done[i])return true;
        
        if(l)return false;
        ss.insert(i);
        for(int j = 0;j<g[i].size();j++){
            if(!dfs(g[i][j],ss,done,g))return false;
        }
        done[i] = true;
        return true;
        
    }
};
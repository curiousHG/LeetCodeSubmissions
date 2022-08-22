class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans,empty;
        vector<vector<int>> gr(n, vector<int>());
        vector<bool> done(n, false);
        for(auto x:pre){
            gr[x[0]].push_back(x[1]);
        }
        for(int i = 0;i<n;i++){
            unordered_set<int> ss;
            if(!dfs(i, gr, done, ss, ans))return empty;
        }
        return ans;
        
    }
    bool dfs(int i , vector<vector<int>> &gr, vector<bool> &done, unordered_set<int> &ss, vector<int> &ans){
        if(done[i])return true;
        if(ss.find(i)!=ss.end())return false;
        ss.insert(i);
        for(auto j:gr[i]){
            if(!dfs(j, gr, done, ss,ans))return false;
        }
        done[i] = true;
        ans.push_back(i);
        return true;
        
        
        
    }
};
class Solution {
public:
    bool dfs(int i, vector<bool> &vis, vector<bool> &col,int prev, vector<vector<int>> &gr){
        if(vis[i]){
            if(col[i]==prev)return false;
            return true;
        }
        vis[i] = true;
        col[i] = prev==0?1:0;
        for(int j:gr[i]){
            if(!dfs(j, vis, col, col[i], gr))return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& e) {
        vector<vector<int>> gr(n+1, vector<int>());
        for(int i = 0;i<e.size();i++){
            gr[e[i][0]].push_back(e[i][1]);
            gr[e[i][1]].push_back(e[i][0]);
        }
        vector<bool> vis(n+1, false);
        vector<bool> col(n+1,0);
        for(int i = 1;i<=n;i++){
            if(vis[i])continue;
            if(!dfs(i, vis,col, 0, gr))return false;
        }
        return true;
    }
};
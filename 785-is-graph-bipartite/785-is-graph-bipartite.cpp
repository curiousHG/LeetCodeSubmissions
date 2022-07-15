class Solution {
public:
    vector<int> col;
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        // vis = vector<bool>(n,false);
        col = vector<int>(n,-1);
        for(int i = 0;i<n;i++){
            if(col[i]!=-1)continue;
            if(!dfs(i,g,0))return false;
        }
        return true;
    }
    bool dfs(int i,vector<vector<int>>& g,bool c){
        int val = c==0?1:0;
        if(col[i]!=-1)return col[i]!=val;
        col[i] = c;
        for(int j = 0;j<g[i].size();j++){
            if(col[g[i][j]]!=-1 && col[g[i][j]]==c)return false;
            else if(!dfs(g[i][j],g,val))return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    bool dfs(int i, int j, int prev,vector<vector<bool>> &w, vector<vector<bool>> &vis,vector<vector<int>>& h){
        if(i<0 || j<0 || i>=w.size() || j>=w[0].size() || h[i][j]>prev)return false;
        if(vis[i][j]) return w[i][j];
        vis[i][j]= true;
        if(w[i][j])return true;
        
        w[i][j] = dfs(i+1, j, h[i][j], w, vis, h)||dfs(i-1, j, h[i][j], w, vis, h)||dfs(i, j+1, h[i][j], w, vis, h)||dfs(i, j-1, h[i][j], w, vis, h);
        if(!w[i][j])vis[i][j] = false;
        return w[i][j];
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        vector<vector<bool>> A(n, vector<bool>(m, false));
        vector<vector<bool>> B(n, vector<bool>(m, false));
        vector<vector<bool>> visA(n, vector<bool>(m, false));
        vector<vector<bool>> visB(n, vector<bool>(m, false));
        for(int i = 0;i<n;i++){
            A[i][0] = true;
            B[i][m-1] = true;
        }
        for(int i = 0;i<m;i++){
            A[0][i] = true;
            B[n-1][i] = true;
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(i, j, INT_MAX, A, visA, heights);
                dfs(i, j, INT_MAX, B, visB, heights);
                if(A[i][j] && B[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};
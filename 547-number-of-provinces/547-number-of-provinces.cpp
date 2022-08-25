class Solution {
public:
    vector<bool> vis;
    void mark(int j, vector<vector<int>>& isC,vector<bool> &vis){
        if(vis[j])return;
        vis[j] = true;
        for(int i = 0;i<isC.size();i++){
            if(isC[j][i])mark(i, isC,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size(),ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                mark(i, isC,vis);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(int i, int j,int prev,int l,vector<vector<int>>& hei, vector<vector<bool>> &vis){
        int n = hei.size(),m = hei[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || vis[i][j])return;
        if(abs(hei[i][j]-prev)>l)return;
        vis[i][j] = true;
        dfs(i+1, j, hei[i][j], l, hei, vis);
        dfs(i-1, j, hei[i][j], l, hei, vis);
        dfs(i, j-1, hei[i][j], l, hei, vis);
        dfs(i, j+1, hei[i][j], l, hei, vis);
        
    }
    int poss(int lim, vector<vector<int>>& hei){
        int n = hei.size(),m = hei[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(0,0,hei[0][0],lim, hei, vis);
        return vis[n-1][m-1];
        
    }
    int minimumEffortPath(vector<vector<int>>& hei) {
        int l = 0,h = INT_MAX, mid;
        while(l<h){
            mid = l+ (h-l)/2;
            if(poss(mid, hei)){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
        
        
    }
};
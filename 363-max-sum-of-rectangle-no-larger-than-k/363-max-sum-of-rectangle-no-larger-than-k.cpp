class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &pre,int t,int m){
        set<int> ss;
        int maxi = -INT_MAX;
        for(int k = 1;k<=m;k++){
            int val = pre[j][k]-pre[i][k];
            
            auto ind = ss.lower_bound(val-t);
            if(ind!=ss.end())maxi = max(maxi, val - *ind);
            if(val<=t)maxi = max(maxi, val);
            ss.insert(val);
        }
        return maxi;
        
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                pre[i+1][j+1] = pre[i+1][j]+pre[i][j+1]+mat[i][j]-pre[i][j];
            }
        }
        int ans = -INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<=n;j++){
                ans = max(ans, solve(i, j, pre, k, m));
            }
        }
        return ans;
        
    }
};
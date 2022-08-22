class Solution {
public:
    int dp(int r, int c1, int c2, vector<vector<vector<int>>> &memo, int n, int m,vector<vector<int>>& grid){
        if(r==n || c1<0 || c2<0 || c1>m-1 || c2>m-1)return 0;
        if(memo[r][c1][c2]!=-1)return memo[r][c1][c2];
        
        memo[r][c1][c2] = grid[r][c1];
        if(c1!=c2)memo[r][c1][c2]+=grid[r][c2];
        int val = 0;
        for(int i = -1;i<=1;i++){
           for(int j = -1;j<=1;j++){
               val = max(val, dp(r+1, c1+i, c2+j, memo,n,m, grid));
           }
        }
        memo[r][c1][c2]+=val;
        // cout<<r<<" "<<c1<<" "<<c2<<" "<<memo[r][c1][c2]<<endl; 
        return memo[r][c1][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return dp(0,0,m-1, memo, n, m,grid);
    }
};
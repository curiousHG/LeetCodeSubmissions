class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> time(n+2, vector<int>(m+2, INT_MAX));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    time[i+1][j+1] = 0; 
                }else{
                    int k = min(time[i][j+1],time[i+1][j]);
                    if(k!=INT_MAX)time[i+1][j+1] = 1+k;
                }
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(grid[i][j]==0)continue;
                int k = min(time[i+1][j+2],time[i+2][j+1]);
                if(k!=INT_MAX)time[i+1][j+1] = min(time[i+1][j+1],1+k);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans[i][j] = time[i+1][j+1];
            }
        }
 
        return ans;
    }
};
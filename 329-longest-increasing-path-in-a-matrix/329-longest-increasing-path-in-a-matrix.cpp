class Solution {
public:
    vector<vector<int>> max_prev;
    int n,m;
    int maxi = 0;
    void dfs(int dis,int i, int j, vector<vector<int>>& matrix){
        maxi = max(maxi,dis);
        if(dis>max_prev[i][j]){
            max_prev[i][j] = dis;
            if(i<n-1 && matrix[i+1][j]>matrix[i][j])dfs(dis+1,i+1,j,matrix);
            if(i>0 && matrix[i-1][j]>matrix[i][j])dfs(dis+1,i-1,j,matrix);
            if(j>0 && matrix[i][j-1]>matrix[i][j])dfs(dis+1,i,j-1,matrix);
            if(j<m-1 && matrix[i][j+1]>matrix[i][j])dfs(dis+1,i,j+1,matrix);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        max_prev = vector<vector<int>>(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(1,i,j,matrix);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = 0,col = 0,n = mat.size(),m = mat[0].size();
        if(r*c!=n*m)return mat;
        vector<vector<int>> ans;
        ans.push_back(vector<int>(c));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(col==c){
                    ans.push_back(vector<int>(c));
                    row++;
                    col=0;
                }
                ans[row][col] = mat[i][j];
                col++;
            }
        }
        return ans;
    }
    
};
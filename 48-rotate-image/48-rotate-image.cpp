class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n/2;i++){
            for(int j = i;j<n-1-i;j++){
                // cout<<matrix[i][j]<<endl;
                swap(matrix, i,j,n);
            }
            
        }
        
    }
    void swap(vector<vector<int>>& matrix,int i,int j,int n){
        int temp = matrix[i][j];
        // 0 1;
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = temp;
        // cout<<i<<" "<<j;
        // cout<<j<<" "<<n-1-i;
        // cout<<n-1-
    }
};
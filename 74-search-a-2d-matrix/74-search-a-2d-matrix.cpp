class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int i = 0;
        while(i<n){
            if(matrix[i][m-1]<target)i++;
            else if(matrix[i][m-1]==target)return true;
            else break;
        }
        if(i<n)return binary_search(matrix[i].begin(),matrix[i].end(),target);
        return false;
    }
};
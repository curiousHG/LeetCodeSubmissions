class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans= 0,n = mat.size();
        for(int i = 0;i<n;i++){
            ans+=mat[i][i];
            if(n-1-i!=i)ans+=mat[n-1-i][i];
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int p) {
        vector<vector<int>> mat(p,vector<int>(p));
        int c = 1;
        int n = p,m = p;
        vector<int> ans;
        int i = 0,j = 0,r = m-1,d = n-1;
        while(j<m)mat[i][j++] = c++;
        j--;
        i++;
        int ki = 0,kj = 0,diri = 1,dirj = -1;
        while(r>=0 && d>0){
            while(ki<d){
                mat[i][j] = c++;
                i+=diri;
                ki++;
            }
            i-=diri;
            j+=dirj;
            while(kj<r){
                mat[i][j] = c++;
                j+=dirj;
                kj++;
            }
            j-=dirj;
            i-=diri;
            ki=0;kj =0;
            r--;d--;
            diri*=-1;
            dirj*=-1;
            
        }
        
        return mat;
    }
};
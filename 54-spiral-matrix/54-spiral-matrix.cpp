class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int> ans;
        int i = 0,j = 0,r = m-1,d = n-1;
        while(j<m){
            ans.push_back(mat[i][j]);
            j++;
        }
        j--;
        i++;
        int ki = 0,kj = 0,diri = 1,dirj = -1;
        while(r>=0 && d>0){
            while(ki<d){
                ans.push_back(mat[i][j]);
                i+=diri;
                ki++;
            }
            i-=diri;
            j+=dirj;
            while(kj<r){
                ans.push_back(mat[i][j]);
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
        
        return ans;
        
        
    }
};
class Solution {
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        int k = n-1;
        while(k>=0){
            int i = k,j = 0,l;
            vector<int> arr;
            while(i<n && j<m){
                arr.push_back(mat[i++][j++]);
            }
            sort(arr.begin(),arr.end());
            i = k,j = 0,l = 0;
            while(i<n && j<m){
                mat[i][j] = arr[l];
                i++;l++;j++;
            }
            k--;
        }
        k = 1;
        while(k<m){
            int i = 0,j = k,l;
            vector<int> arr;
            while(i<n && j<m){
                arr.push_back(mat[i++][j++]);
            }
            sort(arr.begin(),arr.end());
            i = 0,j = k,l = 0;
            while(i<n && j<m){
                mat[i][j] = arr[l];
                j++;l++;i++;
            }
            k++;
        }
        return mat;
        
    }
};
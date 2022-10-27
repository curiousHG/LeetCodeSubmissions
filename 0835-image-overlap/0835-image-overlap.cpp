
#define pii pair<int,int>
class Solution {
public:
    bool check(int nx, int ny,int n){
        return nx<n && nx>=0 && ny>=0 && ny<n;
    }
    int maxcov(int l, int r,vector<vector<int>>& img1, vector<vector<int>>& img2){
        int m1 = 0,m2 = 0;
        int n = img1.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int nx = i+l,ny = j+r;
                if(check(nx,ny,n)){
                    if(img1[nx][ny]==1 && img2[i][j]==1)m1++;
                    if(img2[nx][ny]==1 && img1[i][j]==1)m2++;
                }
            }
        }
        return max(m1, m2);
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxi = 0;
        for(int i = -n;i<=n;i++){
            for(int j = -n;j<=n;j++){
                maxi = max(maxi, maxcov(i, j, img1, img2));
                
            }
        }
        return maxi;
        
    }
};
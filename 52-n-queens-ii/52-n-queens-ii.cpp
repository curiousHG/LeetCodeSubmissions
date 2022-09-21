class Solution {
public:
    int ans = 0;
    vector<vector<bool>> bo;
    bool noclash(int i, int j,int n){
        for(int k = 0;k<=i;k++){
            if(bo[i-k][j])return false;

        }
        for(int k = 0;k<=min(i,j);k++){
            if(bo[i-k][j-k])return false;
        }
        while(i>=0 && j<n){
            if(bo[i][j])return false;
            i--;j++;
        }
        return true;
    }
    void solve(int i,int n){
        if(i==n){
            ans++;
            return;
        }
        for(int j = 0;j<n;j++){
            bool b = noclash(i, j,n);
            // cout<<i<<" "<<j<<" "<<b<<endl;
            if(b){
                bo[i][j] = true;
                solve(i+1, n);
                bo[i][j] = false;
            }
        }

    }
    int totalNQueens(int n) {
        bo.resize(n, vector<bool>(n,false));
        solve(0,n);
        return ans;
        
    }
};
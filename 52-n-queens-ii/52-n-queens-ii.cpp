class Solution {
public:
    int ans = 0;
    bool safe(int i,int j, vector<string> &b){
        int n = b.size();
        for(int k = 0;k<i;k++){
            if(b[k][j]=='Q')return false;
        }
        int r = i,c = j;
        while(r>=0 && c>=0){
            if(b[r][c]=='Q')return false;
            r--;c--;
        }
        r = i,c = j;
        while(r>=0 && c<n){
            if(b[r][c]=='Q')return false;
            r--;c++;
        }
        return true;
    }
    void solve(int i,int n, vector<string> &b){
        if(i==n){
            ans++;
            return;
        }
        for(int j = 0;j<n;j++){
            if(safe(i,j,b)){
                b[i][j] = 'Q';
                solve(i+1, n, b);
                b[i][j] = '.';
            }

        }
    }
    int totalNQueens(int n) {
        ans = 0;
        vector<string> b(n,string(n,'.'));
        solve(0,n, b);
        return ans;
    }

};
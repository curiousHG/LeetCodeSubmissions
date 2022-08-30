class Solution {
public:
    int ans = 0;
    const int mod = 1e9+7;
    vector<int> dx = {1,0,0,-1}, dy = {0,1,-1,0}; 
    int m,n;
    vector<vector<vector<int>>> memo;
    int dp(int i, int j, int k){
        if(k<0)return 0;
        if(check(i,j))return 1;
        if(memo[i][j][k]!=-1)return memo[i][j][k];
        int val = 0;
        for(int l = 0;l<4;l++){
            val = (val+dp(i+dx[l], j+dy[l],k-1))%mod;
        }
        return memo[i][j][k] = val;      
    }
    bool check(int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)return true;
        return false;
    }
    int findPaths(int a, int b, int mm, int R, int C) {
        memo.resize(a, vector<vector<int>>(b, vector<int>(mm+1,-1)));
        m = a;
        n = b;
        return dp(R, C, mm);
    }
};
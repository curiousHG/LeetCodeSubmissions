class Solution {
public:
    int ans = 0;
    int mod = 1e9+7;
    vector<int> dx = {1,0,0,-1}, dy = {0,1,-1,0}; 
    int m,n;
    vector<vector<vector<int>>> memo;
    int dp(int i, int j, int k){
        if(k<0)return 0;
        if(check(i,j))return 1;
        if(memo[i][j][k]!=-1)return memo[i][j][k];
        long long val = ((dp(i-1, j,k-1)+dp(i+1, j, k-1))%mod+(dp(i, j+1, k-1)+dp(i, j-1, k-1))%mod)%mod;
        memo[i][j][k] = val%mod;
        return val;        
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
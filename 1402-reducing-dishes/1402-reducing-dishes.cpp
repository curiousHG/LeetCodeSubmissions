class Solution {
public:
    vector<vector<int>> memo;
    int ans = 0;
    int dp(int i, int j, vector<int>& arr) {
        // cout<<i+1<<" "<<j<<endl;
        if(j>i+1)return -INT_MAX;
        
        if(memo[i][j]!=-INT_MAX)return memo[i][j];
        
        int val = -INT_MAX;
        val = max(val, dp(i-1, j-1, arr)+arr[i]*j);
        val = max(val, dp(i-1, j,arr));
        ans = max(ans, val);
        return memo[i][j] = val;
        

    }
    int maxSatisfaction(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        memo.resize(n, vector<int>(n+1, -INT_MAX));
        memo[0][1] = a[0];
        for(int i= 1;i<n;i++){
            memo[i][1] = max(memo[i-1][1], a[i]);
        }
        for(int j = n;j>=1;j--){
            dp(n-1, j, a);
        }
       

        return ans;

        
    }
};
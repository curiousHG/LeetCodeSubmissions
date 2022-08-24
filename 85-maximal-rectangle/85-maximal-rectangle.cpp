class Solution {
public:
    int maxR(vector<int> &arr){
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        for(int i = 1;i<n;i++){
            int p = i-1;
            while(p>-1 && arr[p]>=arr[i])p =left[p];
            left[i] = p;
        }
        for(int i = n-2;i>=0;i--){
            int p = i+1;
            while(p<n && arr[p]>=arr[i])p = right[p];
            right[i] = p;
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int l = i-left[i]-1 + right[i] - i;
            // cout<<l<<" ";
            maxi = max(maxi, l*arr[i]);
        }
        // cout<<"|"<<maxi<<"|";
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& A) {
        int n = A.size(),m = A[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]=='1')dp[i+1][j] = dp[i][j]+1;
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans, maxR(dp[i]));
        }
        return ans;    
    }
};

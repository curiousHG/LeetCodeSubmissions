#define ll long long
int mod = 1e9+7;
class Solution {
public:
    ll cor(int r){
        return (r+2)*(r+1)/2;
        
    }
    int countOrders(int n) {
        vector<ll> dp(n+2,0ll);
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = cor(2*(i-1))*dp[i-1];
            dp[i]%=mod;
        }
        return dp[n];
        
    }
};
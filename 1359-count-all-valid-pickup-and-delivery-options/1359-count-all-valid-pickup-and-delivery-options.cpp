#define ll long long
int mod = 1e9+7;
class Solution {
public:
    ll cor(int r){
        return (r+2)*(r+1)/2;
        
    }
    int countOrders(int n) {
        ll prev = 1;
        for(int i = 2;i<=n;i++){
            prev = cor(2*(i-1))*prev;
            prev%=mod;
        }
        return prev;
        
    }
};
#define ll long long
class Solution {
public:
    int pos(int n){
        return 1 + (int) log2(n);
    }
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int s = pos(i);
            ans<<=s;
            ans+=i;
            ans = ans%mod;
        }
        return ans;
    }
};
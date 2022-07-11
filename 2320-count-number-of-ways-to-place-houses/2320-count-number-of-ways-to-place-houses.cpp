class Solution {
public:
    int countHousePlacements(int n) {
        long long int a = 1,b = 2,c = 1,d,e,f;
        int mod = 1e9+7;
        for(int i = 2;i<=n;i++){
            d = (a+b+c)%mod;
            e = (2*a+b)%mod;
            f = a%mod;
            a = d;b = e;c = f;
            
        }
        return (a+b+c)%mod;
        
    }
};
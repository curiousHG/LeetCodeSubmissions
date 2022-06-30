class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n+1,true);
        p[0] = false;
        p[1] = false;
        for(int i = 2;i<n;i++){
            if(!p[i])continue;
            int j = 2;
            while(j*i<=n){
                p[j*i] = false;
                j++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)ans+=p[i];
        return ans;
    }
};
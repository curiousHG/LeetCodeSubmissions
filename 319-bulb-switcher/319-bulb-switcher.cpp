class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0)return 0;
        int ans = 0;
        for(int i = 1;i*i<=n;i++){
            ans++;
        }
        return ans;
    }
};
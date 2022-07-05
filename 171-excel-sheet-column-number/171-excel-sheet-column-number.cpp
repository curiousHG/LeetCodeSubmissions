class Solution {
public:
    int titleToNumber(string c) {
        int ans = 0,n = c.length();
        for(int i = n-1;i>-1;i--){
            cout<<pow(26,n-1-i)<<endl;
            ans+=(c[i]-'A'+1)*(pow(26,n-1-i));
        }
        // cout<<pow(26,1)<<endl;
        return ans;
    }
};
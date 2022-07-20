class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        if(__builtin_popcount(n)==1){
            int k = 0;
            while(n){
                n>>=1;
                k++;
            }
            // cout<<k<<endl;
            if(k%2)return true;
        }
        return false;
    }
};
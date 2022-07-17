class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int t = 2,a = 1;
        while(true){
            int val = n-(t*(t-1)/2);
            // cout<<val%t<<" ";
            if(val%t==0 && val>0)a++;
            if(val/t<1)break;
            t++;
        }
        return a;
    }
};
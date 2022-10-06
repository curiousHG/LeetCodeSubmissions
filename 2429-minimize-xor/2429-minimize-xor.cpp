class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        if(a==b)return num1;
        if(a>b){
            int ans = num1;
            int k = a-b;
            for(int i = 0;i<32;i++){
                if(k==0)break;
                if(num1 & 1<<i){
                    ans -=1<<i;
                    k--;
                }
            }
            return ans;
        }
        int ans = num1;
        int k = b-a;
        for(int i = 0;i<32;i++){
            if(k==0)break;
            if(!(num1 & 1<<i)){
                ans +=1<<i;
                k--;
            }
        }
        return ans;
        
    }
};
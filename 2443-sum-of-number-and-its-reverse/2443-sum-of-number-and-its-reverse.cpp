class Solution {
public:
    int rev(int x){
        int ans = 0;
        while(x){
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0;i<=num;i++){
            if(i+rev(i)==num)return true;
        }
        return false;
    }
};
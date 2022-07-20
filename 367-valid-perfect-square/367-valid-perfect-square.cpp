class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1,r = num/2,mid;
        while(l<r){
            mid = (l+r)/2;
            if(mid*mid==num)return true;
            else if(mid*mid<num)l = mid;
            else r = mid;
            if(l+1==r)break;
        }
        if(l*l==num || r*r==num)return true;
        return false;
    }
};
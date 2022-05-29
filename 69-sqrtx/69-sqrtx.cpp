class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        if(x==1){
            return 1;
        }
        while(low<high){
            int mid = (low+high)/2;
            if(mid>x/mid){
                high = mid;
            }else{
                low = mid;
            }
            if(low+1==high)break;
        }
        return low;
    }
};
class Solution {
public:
    bool poss(vector<int>& nums, int lim, int m){
        int c = 1,sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>lim){
                c++;
                sum = nums[i];
            }
        }
        if(m>=c)return true;
        return false;
        
    }
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(),nums.end());
        int r = INT_MAX;
        int mid;
        while(l<r){
            mid = l +(r-l)/2;
            // cout<<l<<" "<<r<<"|";
            if(poss(nums, mid, m)){
                r = mid;
            }else{
                l = mid;
            }
            if(l+1==r)break;
            
        }
        if(poss(nums, l, m))return l;
        return r;
        
    }
};
/*


*/ 
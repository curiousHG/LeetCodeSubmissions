class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        if(nums[l]>=target)return l;
        else if(nums[r]<target)return r+1;
        else if(nums[r]==target)return r;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]<target)l = mid;
            else if(nums[mid]>target)r = mid;
            else return mid;
            if(l+1==r){
                break;
            }
        }
        return l+1;
    }
};
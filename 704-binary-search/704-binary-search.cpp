class Solution {
public:
    int search(vector<int>& nums, int t) {
        int i = 0,j = nums.size()-1,mid;
        while(i<=j){
            mid = (i+j)/2;
            if(nums[mid]==t)return mid;
            if(nums[mid]<t)i = mid+1;
            else j = mid-1;
        }
        return -1;
        
        
    }
};
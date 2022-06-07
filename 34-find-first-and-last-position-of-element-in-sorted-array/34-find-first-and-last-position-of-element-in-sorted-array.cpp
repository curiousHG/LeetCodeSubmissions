class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int r = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> ans;
        if(nums.size()==0||l==nums.size() || nums[l]!=target){
            ans = {-1,-1};
        }else{
            ans = {l,r-1};
        }
        return ans;
    }
};
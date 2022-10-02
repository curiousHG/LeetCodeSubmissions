class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxs(n);
        maxs[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            maxs[i] = max(nums[i], maxs[i+1]);
        }
        int mini = nums[0];
        for(int i = 1;i<n;i++){
            if(mini<nums[i] && nums[i]<maxs[i])return true;
            mini = min(mini ,nums[i]);
        }
        return false;
    }
};
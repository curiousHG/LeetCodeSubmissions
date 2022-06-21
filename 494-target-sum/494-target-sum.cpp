class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, target, 0,0);
        return count;
    }
    void solve(vector<int>& nums, int target,int cur,int i){
        if(i==nums.size()){
            if(cur==target)count++;
            return;
        }
        solve(nums, target, cur+nums[i],i+1);
        solve(nums,target,cur-nums[i],i+1);
    }
};
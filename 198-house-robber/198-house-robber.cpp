class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0];
        
        for(int i = 1;i<n;i++){
            if(i>1){
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }else{
                dp[i] = max(nums[i],nums[i-1]);
            }
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX,n = nums.size(),ans;
        for(int i = 0;i+2<n;i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            int l= i+1, r = n-1,sum;
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<diff){
                    diff = abs(sum-target);
                    ans= sum;
                }
                if(diff==0)return sum;
                if(sum<target)l++;
                else r--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(lis.size()==0)lis.push_back(nums[i]);
            else if(lis.back()<nums[i])lis.push_back(nums[i]);
            else if(lis.front()>nums[i])lis.front() = nums[i];
            else{
                int ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};

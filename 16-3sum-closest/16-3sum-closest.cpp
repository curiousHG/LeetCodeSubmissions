class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX,n = nums.size(),ans;
        for(int i = 0;i+2<n;i++){
            int l= i+1, r = n-1,sum = nums[i]+nums[l]+nums[r];
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<diff){
                    // cout<<sum<<" "<<target<<" "<<diff<<endl;
                    
                    diff = abs(sum-target);
                    ans= sum;
                }
                // cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<endl;
                if(diff==0)return sum;
                if(sum<target)l++;
                else r--;
            }
        }
        return ans;
    }
};
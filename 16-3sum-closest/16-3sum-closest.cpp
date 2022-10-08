class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int diff = INT_MAX, best = nums[0]+nums[1]+nums[2],sum;
        for(int i= 0;i<n;i++){
            int l = i+1,r = n-1;
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                if(sum==target)return sum;
                if(abs(sum-target)>=diff){
                    if(target>sum)l++;
                    else r--;
                }else{
                    best = sum;
                    diff = abs(sum-target);
                }
            }
        }
        return best;
    }
};
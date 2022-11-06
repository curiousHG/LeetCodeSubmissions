class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0,prev = 0,maxi = 0,n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi += i*nums[i];
        }
        prev = maxi;
        for(int i = n-1;i>=0;i--){
            prev = prev+sum-nums[i]*n;
            // cout<<prev<<endl;
            maxi = max(maxi, prev);
        }
        return maxi;
    }
};
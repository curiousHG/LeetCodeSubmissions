class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1;
        int maxi = 0;
        while(i<j){
            int vol = min(nums[i],nums[j]);
            vol = (j-i)*vol;
            maxi = max(maxi, vol);
            if(nums[i]<nums[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
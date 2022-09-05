class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0,l = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1)l++;
            else{
                maxi = max(maxi, l);
                l = 0;
            }
        }
        maxi = max(maxi, l);
        return maxi;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curmax = 0,n = nums.size();
        for(int i = 0;i<n;i++){
            if(i<=curmax){
                curmax = max(curmax, i+nums[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};
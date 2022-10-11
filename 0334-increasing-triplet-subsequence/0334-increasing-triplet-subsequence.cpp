class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> mini(n, INT_MAX),maxi(n, 0);
        mini[0] = nums[0];
        maxi[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            mini[i] = min(nums[i], mini[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            maxi[i] = max(nums[i], maxi[i+1]);
        }
        for(int i = 1;i<n-1;i++){
            if(nums[i]>mini[i-1] && nums[i]<maxi[i+1])return true;
        }
        return false;
    }
};
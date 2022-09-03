class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp1(n+3,0),dp2(n+3,0);
        for(int i = 0;i<n-1;i++){
            dp1[i+3] = nums[i]+max(dp1[i+1],dp1[i]);
            dp2[i+3] = nums[i+1]+max(dp2[i+1],dp2[i]);
        }
        int a = *max_element(dp1.begin(),dp1.end());
        int b = *max_element(dp2.begin(),dp2.end());
        return max(a,b);
    }
};


/*

2 4 5 6 2 3 5


*/ 
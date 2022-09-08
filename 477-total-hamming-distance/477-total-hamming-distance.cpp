class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> o(32,0);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<32;j++){
                o[j]+=nums[i]&1;
                nums[i]>>=1;
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++){
            // cout<<o[i]<<" ";
            ans+=o[i]*(n-o[i]);
        }
        return ans;
        
    }
};
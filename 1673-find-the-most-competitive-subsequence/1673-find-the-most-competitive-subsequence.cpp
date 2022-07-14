class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(ans.empty()){
                ans.push_back(nums[i]);
                continue;
            }
            while(ans.size()>0 && ans.back()>nums[i] &&i+k<n+ans.size())ans.pop_back();
            if(ans.size()<k)ans.push_back(nums[i]);
            
        }
        return ans;
    }
};
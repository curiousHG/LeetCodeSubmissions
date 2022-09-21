class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& qs) {
        vector<int> ans;
        int s = 0;
        for(int i:nums){
            if(i%2==0)s+=i;
        }
        for(int i = 0;i<qs.size();i++){
            int j = qs[i][1],val = qs[i][0];
            if(nums[j]%2){
                nums[j]+=val;
                if(nums[j]%2==0){
                    s+=nums[j];
                }
            }else{
                nums[j]+=val;
                if(nums[j]%2){
                    s-=(nums[j]-val);
                }else{
                    s+=val;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
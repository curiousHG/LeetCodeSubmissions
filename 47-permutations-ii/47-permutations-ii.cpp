class Solution {
public:
    void solve(int i, vector<int> ind, vector<vector<int>> &ans){
        if(i==ind.size()){
            ans.push_back(ind);
            return;
        }
        for(int j = i;j<ind.size();j++){
            if(j>i && ind[i]==ind[j])continue;
            swap(ind[i],ind[j]);
            solve(i+1,ind, ans);
            // swap(ind[i],ind[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans);
        return ans;
    }
};
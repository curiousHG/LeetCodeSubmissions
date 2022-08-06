class Solution {
public:
    void solve(int i, vector<int> &ind, vector<vector<int>> &ans){
        if(i==ind.size()){
            ans.push_back(ind);
            return;
        }
        for(int j = i;j<ind.size();j++){
            swap(ind[i],ind[j]);
            solve(i+1,ind, ans);
            swap(ind[i],ind[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ind;
        for(int i = 0;i<n;i++)ind.push_back(i);
        solve(0,ind,ans);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<ans.size();j++){
                ans[j][i] = nums[ans[j][i]];
            }
        }
        return ans;
    }
};
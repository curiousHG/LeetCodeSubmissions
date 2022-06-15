class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> cur;
        solve(cur, cand ,0,target,0);
        return ans;
    }
    void solve(vector<int> cur,vector<int> cand, int sum, int target, int start){
        if (target==sum){
            ans.push_back(cur);
            return;
        }
        for(int i = start;i<cand.size();i++){
            if(sum+cand[i]<=target){
                cur.push_back(cand[i]);
                solve(cur, cand, sum+cand[i],target,i);
                cur.pop_back();
            }
        }
    }
};
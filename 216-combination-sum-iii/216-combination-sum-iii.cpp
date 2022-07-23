class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(9,0,k,0,n,vector<int>(), ans);
        return ans;
    }
    void solve(int ind,int count,int k, int curSum, int n, vector<int> temp, vector<vector<int>> &ans){
        // cout<<curSum<<endl;
        if(curSum>n)return;
        if(curSum==n){
            if(count==k){
                ans.push_back(temp);
                return;
            }
            return;
        }
        for(int i = ind;i>0;i--){
            temp.push_back(i);
            solve(i-1,count+1, k, curSum+i, n, temp, ans);
            temp.pop_back();
        }
    }
};
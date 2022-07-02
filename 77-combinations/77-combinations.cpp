class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(ans,a,0,1,k,n);
        return ans;
    }
    void solve(vector<vector<int>> &ans,vector<int> &temp,int i,int j,int k,int n){
        if(i==k){
            ans.push_back(temp);
            return;
        }
        for(int l =j;l<=n;l++){
            temp.push_back(l);
            solve(ans,temp, i+1,l+1,k,n);
            temp.pop_back();
        }
    }
};
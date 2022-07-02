class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        solve(a,0,1,k,n);
        return ans;
    }
    void solve(vector<int> &temp,int i,int j,int k,int n){
        if(i==k){
            ans.push_back(temp);
            return;
        }
        for(int l =j;l<=n;l++){
            temp.push_back(l);
            solve(temp, i+1,l+1,k,n);
            temp.pop_back();
        }
    }
};
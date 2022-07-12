class Solution {
public:
    
    int t,n;
    vector<vector<int>> combinationSum2(vector<int>& ca, int target) {
        sort(ca.begin(),ca.end());
        vector<vector<int>> ans;
        t = target;
        n = ca.size();
        vector<int> temp;
        solve(ans, temp, 0,0,ca);
        return ans;
    }
    void solve(vector<vector<int>> &ans,vector<int> &temp, int sumi,int i,vector<int>& arr){
        if(sumi>t)return;
        if(sumi==t){
            ans.push_back(temp);
            return;
        }for(int j = i;j<n;j++){
            if(j>i && arr[j-1]==arr[j])continue;
            temp.push_back(arr[j]);
            solve(ans, temp, sumi+arr[j], j+1, arr);
            temp.pop_back();
            
        }
        
    }
};
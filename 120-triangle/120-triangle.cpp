void pv(vector<int> &A){
    for(int i= 0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<int> dp;
        dp.push_back(t[0][0]);
        for(int i = 1;i<t.size();i++){
            vector<int> temp;
            temp.push_back(dp[0]+t[i][0]);
            for(int j = 1;j<t[i].size()-1;j++){
                temp.push_back(min(dp[j-1],dp[j])+t[i][j]);
            }
            temp.push_back(dp[i-1]+t[i][t[i].size()-1]);
            
            dp = temp;
            // pv(dp);
        }
        int ans = INT_MAX;
        for(int i= 0;i<dp.size();i++)ans = min(ans, dp[i]);
        return ans;
    }
};
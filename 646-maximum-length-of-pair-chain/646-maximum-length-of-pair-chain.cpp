class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        vector<pair<int,int>> dp;
        sort(p.begin(),p.end());
        dp.push_back({p[0][1],1});
        int maxi = 1,n = p.size();
        for(int i = 1;i<n;i++){
            int l = 1;
            for(int j = i-1;j>=0;j--){
                if(dp[j].first<p[i][0]){
                    l = max(l, dp[j].second+1);
                }
            }
            dp.push_back({p[i][1],l});
            maxi = max(maxi, l);
        }
        return maxi;
    }
};
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(),k = 0,p;
        int d[3] = {1,7,30};
        vector<int> dp(n+1);
        for(int i = 0;i<n;i++){
            int mini = INT_MAX;
            for(int j = 0;j<3;j++){
                p = lower_bound(days.begin(),days.end(),days[i]-d[j]) - days.begin();
                if(days[p]>days[i])p--;
                if(p==-1)mini = min(mini,costs[j]);
                else{
                    if(days[p]==days[i]-d[j])p++;
                    mini = min(mini, dp[p]+costs[j]);
                }
            }
            // cout<<mini<<endl;
            dp[i+1] = mini;
        }
        return dp[n];
        
        
    }
};
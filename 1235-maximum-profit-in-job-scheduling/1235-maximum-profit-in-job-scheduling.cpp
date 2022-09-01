class Solution {
public:
    int jobScheduling(vector<int>& sT, vector<int>& eT, vector<int>& pro) {
        int n = sT.size();
        vector<vector<int>> jobs(n,vector<int>(3,0));
        for(int i = 0;i<n;i++){
            jobs[i][0]=sT[i];
            jobs[i][1]=eT[i];
            jobs[i][2]=pro[i]; 
        }
        sort(jobs.begin(),jobs.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        // vector<int> dp(n+1, 0);
        // dp[0] = 0;
        map<int,int>dp;
        dp[0]=0;
        for(int i = 0;i<n;i++){
            // dp[i+1] = max(dp[i], dp[i+1]);
            // int l = 0,h = i,mid;
            // while(l<h-1){
            //     mid = (l+h)/2;
            //     if(jobs[mid][1]<=jobs[i][0]){
            //         l = mid;
            //     }else{
            //         h = mid;
            //     }
            // }
            // int val = jobs[l][1]<=jobs[i][0]?dp[l+1]:0;
            // dp[i+1] = max(dp[i+1], val+jobs[i][2]);
            auto fg = dp.upper_bound(jobs[i][0]); //first_greater
            fg--;
            int pro = fg->second+jobs[i][2];
            if(pro>dp.rbegin()->second){
                dp[jobs[i][1]]= pro;
            }
            
            
            
        }
        // return dp[n];
        return dp.rbegin()->second;
    }
};
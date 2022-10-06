#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<ll, int>, vector<pair<ll,int>>>pq;
        ll sum = 0;
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(sum>=k){
                ans = min(ans, i+1);
            }
            while(!pq.empty() && sum+pq.top().first>=k){
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({-sum, i});
        }
        if(ans!=1e9)return ans;
        return -1;
    }
};
#define ll long long
class Solution {
public:
    ll maxi =0;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<ll> pre(n+1,0);
        for(int i = 0;i<n;i++)pre[i+1] = pre[i]+nums[i];
        int i = 0, j = 0;
        ll sum = 0;
        while(i<n && j<n){
            mp[nums[j]]++;
            // cout<<i<<" "<<j<<" "<<maxi<<endl;
            while(mp[nums[j]]!=1){
                mp[nums[i]]--;
                i++;
                // cout<<i<<" "<<j<<" "<<sum<<endl;
            }
            if(j-i+1>=k && j-k+1>=0){
                // cout<<j+1<<" "<<j-k+1<<endl;
                maxi = max(maxi, pre[j+1]-pre[j-k+1]);
            }
            j++;
            
        }
        return maxi;
    }
};
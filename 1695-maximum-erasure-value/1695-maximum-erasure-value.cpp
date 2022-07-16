class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi = 0,n = nums.size(),st = -1;
        int l = 0,r = 0;
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i= 0;i<n;i++)pre[i+1] = pre[i]+nums[i];
        for(int i= 0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                if(st<m[nums[i]])st = m[nums[i]]; 
            }
            if(maxi<pre[i+1]-pre[st+1]){
                r = i;l = st;
                maxi = pre[i+1]-pre[st+1];
            }
            m[nums[i]] = i;
        }
        // cout<<l<<" "<<r<<endl;
        return maxi;
    }
};
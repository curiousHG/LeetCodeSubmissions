class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),c=0;
        vector<int> prev(n+1);
        prev[0] = 0;
        for(int i = 0;i<n;i++){
            prev[i+1] = prev[i]+nums[i];
        }
        unordered_map<int,int> m;
        // m[0]=1;
        for(int i = 0;i<=n;i++){
            if(m.find(prev[i])!=m.end()){
                c+=m[prev[i]];
            }
            m[prev[i]+k]++;
        }
        return c;
        
    }
};
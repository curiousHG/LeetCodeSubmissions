class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int n = nums.size();
        vector<char> np(n+1,0);
        for(auto k:nums){
            if(k>0 && k<n+1){
                np[k-1] = true;
            }
        }
        
        for(int i=0;i<=n;i++){
            if(!np[i])return i+1;
        }
        
        return INT_MAX;
            
    }
};
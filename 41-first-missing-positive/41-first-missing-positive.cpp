class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(0);
        unordered_set<int> s;
        for(int i= 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        int i = 1;
        while(s.find(i)!=s.end())i++;
        return i;
            
    }
};
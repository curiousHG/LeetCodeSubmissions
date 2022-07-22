class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i= 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i = 1;
        while(s.find(i)!=s.end())i++;
        return i;
            
    }
};
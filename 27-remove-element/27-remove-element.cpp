class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0,n = nums.size();
        while(j<n && i<n){
            if(nums[i]!=val){
                i++;
                j = i;
                continue;
            }
            while(j<n && nums[j]==val)j++;
            if(j<n){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        return i;
    }
};
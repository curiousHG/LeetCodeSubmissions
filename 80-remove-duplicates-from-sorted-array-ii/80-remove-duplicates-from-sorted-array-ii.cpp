class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0,j = 0,k = 0,n = nums.size(),c = 0;
        k = nums[0];
        while(j<n){
            while(j<n && nums[j]==k && c<2){
                nums[i] = nums[j];
                i++;
                j++;
                c++;
            }
            c =0;
            while(j<n && nums[j]==k)j++;
            k = nums[j];
        }
        return i;
    }
};
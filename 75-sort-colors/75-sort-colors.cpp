class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> val = {0,0,0};
        for(int i = 0;i<nums.size();i++)val[nums[i]]++;
        int i = 0;
        for(int j = 0;j<3;j++){
            while(val[j]){
                nums[i] = j;
                val[j]--;
                i++;
            }   
        }
        
    }
};
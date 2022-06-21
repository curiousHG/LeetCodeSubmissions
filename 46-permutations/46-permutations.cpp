class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0&&nums[i-1]>=nums[i])i--;
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j = i;
        int mini = nums[j];
        int ind = j;
        for(int k = j;k<nums.size();k++){
            if(nums[k]>nums[j-1]){
                mini = min(mini,nums[k]);
                ind = k;
            }
        }
        swap(nums[j-1],nums[ind]);
        sort(nums.begin()+j,nums.end());
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ind;
        vector<vector<int>>ans;
        for(int i =0;i<nums.size();i++)ind.push_back(i);
        int per = 1;
        for(int i=1;i<=nums.size();i++)per=per*i;
        for(int i = 0;i<per;i++){
            vector<int> temp;
            for(int j = 0;j<ind.size();j++){
                temp.push_back(nums[ind[j]]);
            }
            nextPermutation(ind);
            ans.push_back(temp);
        }
        return ans;
    }
    
};
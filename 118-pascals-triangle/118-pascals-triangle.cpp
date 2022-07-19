class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        for(int i = 1;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 2;j<i;j++){
                // cout<<i<<" "<<j<<endl;
                temp.push_back(nums[i-2][j-2]+nums[i-2][j-1]);
            }
            if(i!=1)temp.push_back(1);
            nums.push_back(temp);
        }
        return nums;
    }
};
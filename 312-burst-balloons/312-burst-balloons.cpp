class Solution {
public:
    vector<vector<int>> memo;
    int dp(int i, int j, vector<int>& nums){
        if(i+1==j)return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        for(int k = i+1;k<j;k++){
            memo[i][j]= max(memo[i][j], nums[i]*nums[k]*nums[j]+dp(i,k,nums)+dp(k,j,nums));
        }
        return memo[i][j];
    }
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        for(int i = 0;i<nums.size();i++)temp.push_back(nums[i]);
        temp.push_back(1);
        int n= temp.size();
        memo.resize(n, vector<int>(n,-1));
        return dp(0,n-1,temp);
    }
};
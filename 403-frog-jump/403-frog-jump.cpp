class Solution {
public:
    unordered_map<int,vector<int>> memo;
    void dp(int i, int j, int n){
        if(j<0 || i>n || i<0)return;
        if(memo.find(i)==memo.end())return;
        if(i==n)memo[i][j] = 1;
        if(memo[i][j]==1)return;
        // cout<<i<<" "<<j<<"\n";
        memo[i][j] = 1;
        dp(i+j+1, j+1,n);
        dp(i+j-1, j-1,n);
        dp(i+j, j,n);
    }
    
    bool canCross(vector<int>& stones) {
        for(int i:stones){
            memo[i] = vector<int>(2001,-1);
        }
        int last = stones.back();
        memo[0][0] = 1;
        if(stones[1]!=1)return false;
        dp(1, 1,last);
        for(int i =0;i<=2000;i++){
            if(memo[last][i]==1)return true;
        }
        return false;
        
        
    }
};
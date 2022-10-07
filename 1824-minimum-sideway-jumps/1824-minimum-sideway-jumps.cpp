#define inf 1e9
class Solution {
public:
    vector<vector<int>> memo;
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        vector<vector<int>> mat(3, vector<int>(n, 0));
        for(int i = 0;i<n;i++){
            if(obs[i]==0)continue;
            mat[obs[i]-1][i] = 1;
        }
        memo.resize(3, vector<int>(n, inf));
        memo[0][0] = 1;
        memo[1][0] = 0;
        memo[2][0] = 1;
        for(int j = 1;j<n;j++){
            for(int i = 0;i<3;i++){
                if(mat[i][j]==1)continue;
                int val = inf;
                for(int di = -2;di<=2;di++){
                    if(i+di<0 || i+di>2 || mat[i+di][j]==1)continue;
                    if(di==0){
                        val = min(val, memo[i+di][j-1]);
                        
                    }else{
                        val = min(val, 1+ memo[i+di][j-1]);
                    }
                }
                memo[i][j] = val;
            }
            
        }
        int ans = inf;
        for(int i = 0;i<3;i++){
            ans = min(ans, memo[i][n-1]);
        }
        return ans;
        
        
        
        
    }
};
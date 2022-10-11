class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> ans(m,-1);
        for(int j = 0;j<m;j++){
            int c = j;
            for(int i = 0;i<n;i++){
                if(c==0){
                    if(grid[i][c]==-1){
                        c=-1;
                    }else if(c+1<m){
                        if(grid[i][c+1]==-1){
                            c = -1;
                        }else{
                            c++;
                        }
                    }else{
                        c=-1;
                    }
                }else if(c==m-1){
                    if(grid[i][c]==1){
                        c = -1;
                    }else if(c-1>-1){
                        if(grid[i][c-1]==1){
                            c=-1;
                        }else{
                            c--;
                        }
                    }else{
                        c=-1;
                    }
                }else{
                    if(grid[i][c]==-1){
                        if(grid[i][c-1]==-1)c--;
                        else c = -1;
                    }else{
                        if(grid[i][c+1]==1)c++;
                        else c=-1;
                    }
                }
                if(c<0 || c>m-1){
                    c = -1;
                    break;
                }
            }
            ans[j] = c;
        }
        return ans;
    }
};
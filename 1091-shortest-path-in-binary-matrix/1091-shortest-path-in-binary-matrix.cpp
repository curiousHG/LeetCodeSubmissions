#define ppi pair<int,int>
#define ss second
#define ff first
vector<int> dx = {1,1,1,0,-1,-1,-1,0};
vector<int> dy = {-1,0,1,1,1,0,-1,-1};
class Solution {
public:
    bool check(int i ,int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m )return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(grid[0][0]==1)return -1;
        queue<ppi> pq;
        pq.push({0,0});
        grid[0][0] = 1;
        while(!pq.empty()){
            ppi fr = pq.front();
            pq.pop();
            int x = fr.ff;
            int y = fr.ss;
            if(x==n-1 && y==m-1)return grid[x][y];
            for(int k = 0;k<8;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(check(nx, ny, n, m) && grid[nx][ny]==0){
                    pq.push({nx,ny});
                    grid[nx][ny] = grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};
/*
[
[0,1,0,0,0,0],
[0,1,1,1,1,1],
[0,0,0,0,1,1],
[0,1,0,0,0,1],
[1,0,0,1,0,1],
[0,0,1,0,1,0]]
*/ 
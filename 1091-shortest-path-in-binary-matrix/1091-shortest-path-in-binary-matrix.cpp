#define ppi pair<int,pair<int,int>>
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
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        if(grid[0][0]==1)return -1;
        dis[0][0] = 1;
        priority_queue<ppi> pq;
        pq.push({-1,{0,0}});
        while(!pq.empty()){
            ppi fr = pq.top();
            pq.pop();
            int x = fr.ss.ff;
            int y = fr.ss.ss;
            int d = -fr.ff;
            if(x==n-1 && y==m-1)return d;
            // cout<<x<<" "<<y<<"->";
            for(int k = 0;k<8;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(check(nx, ny, n, m) && !grid[nx][ny]){
                    // cout<<nx<<" "<<ny<<"|";
                    if(dis[x][y]+1<dis[nx][ny]){
                        dis[nx][ny] = dis[x][y]+1;
                        pq.push({-dis[nx][ny],{nx,ny}});
                        // cout<<nx<<" "<<ny<<" "<<dis[nx][ny]<<"|";
                    }
                }
            }
            // cout<<endl;
        }
        // return dis[n-1][m-1]==INT_MAX?-1:dis[n-1][m-1];
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
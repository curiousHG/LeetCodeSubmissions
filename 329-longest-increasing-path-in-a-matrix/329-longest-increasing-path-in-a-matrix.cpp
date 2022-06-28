class Solution {
    
public:
    int memo[200][200];
    int longestIncreasingPath(vector<vector<int>>& M) {
        int ylen = M.size(), xlen = M[0].size(), ans = 0;
        for (int i = 0; i < ylen; i++)
            for (int j = 0; j < xlen; j++)
                ans = max(ans, dfs(i,j,M));
        return ans;
    }
    int dfs(int y, int x, vector<vector<int>>& M) {
        if (memo[y][x]) return memo[y][x];
        int val = M[y][x];
        memo[y][x] = 1 + max(
            max(y < M.size() - 1 && M[y+1][x] < val ? dfs(y+1,x,M) : 0,
                y > 0 && M[y-1][x] < val ? dfs(y-1,x,M) : 0),
            max(x < M[0].size() - 1 && M[y][x+1] < val ? dfs(y,x+1,M) : 0,
                x > 0 && M[y][x-1] < val ? dfs(y,x-1,M) : 0));
        return memo[y][x];
    
    }

};
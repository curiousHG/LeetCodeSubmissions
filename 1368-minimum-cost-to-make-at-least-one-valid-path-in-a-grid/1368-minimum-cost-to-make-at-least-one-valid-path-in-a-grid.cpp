struct Node{
    int i, j,dis = INT_MAX;
    Node(int x, int y, int d){
        i = x;
        j = y;
        dis = d;
    }
};
class Compare{
    public:
    bool operator()(Node &A, Node &B){
        return A.dis>B.dis;
    }
};
class Solution {
public:
    vector<vector<int>> memo;
    unordered_map<int, pair<int, int>> dir = {
        {1,{0,1}},
        {3,{1,0}},
        {4,{-1,0}},
        {2,{0,-1}}
    };
    bool valid(int i, int j,vector<vector<int>>& C){
        if(i<0 || j<0 || i>=C.size() || j>= C[0].size())return false;
        return true; 
    }
    int minCost(vector<vector<int>>& grid) {
        int A = grid.size(),B = grid[0].size();
        memo.resize(A, vector<int>(B,INT_MAX));
        priority_queue<Node, vector<Node>, Compare> pq;
        memo[0][0] = 0;
        pq.push(Node(0,0,0));
        while(!pq.empty()){
            Node n = pq.top();

            pq.pop();
            memo[n.i][n.j] = min(n.dis, memo[n.i][n.j]);
            for(auto &i : dir){
                int x = n.i + i.second.first,y = n.j + i.second.second;
                int extra = i.first == grid[n.i][n.j]?0:1;
                if(valid(x,y,grid)){
                    // cout<<n.i<<" "<<n.j<<","<<x<<" "<<y<<"|";
                    if(memo[n.i][n.j]+extra<memo[x][y]){
                        memo[x][y] = memo[n.i][n.j]+extra;
                        pq.push(Node(x,y,memo[x][y]));
                    }

                }
            }
        }
        return memo[A-1][B-1];
    }
};
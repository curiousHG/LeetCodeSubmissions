class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(!vis[f]){
                vis[f] = true;
                for(int i:rooms[f]){
                    q.push(i);
                }
            }
        }
        bool poss = true;
        for(int i = 0;i<n && poss;i++){
            if(!vis[i])poss = false;
        }
        return poss;
    }
};
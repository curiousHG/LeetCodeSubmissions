class Solution {
public:
    unordered_map<int,vector<int>> tr;
    unordered_set<int> vis,res;
    int c = 0;
    void solve(int i){
        if(res.find(i)!=res.end())return;
        if(vis.find(i)!=vis.end())return;
        vis.insert(i);
        c++;
        for(int j:tr[i]){
            solve(j);
        }
        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rt) {
        for(int i = 0;i<n-1;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            tr[a].push_back(b);
            tr[b].push_back(a);
        }
        for(int i:rt)res.insert(i);
        
        solve(0);
        return c;
        
    }
};
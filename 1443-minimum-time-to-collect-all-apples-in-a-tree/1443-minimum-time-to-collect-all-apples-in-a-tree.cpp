class Solution {
public:
    int ans = 0;
    unordered_map<int,vector<int>> tr;
    void solve(int i, int prev,vector<bool>& hA){
        bool childA = false;
        for(int j:tr[i]){
            if(j==prev)continue;
            solve(j,i,hA);
            if(hA[j]){
                childA = true;
                ans+=2;
            }
        }
        if(childA)hA[i] = true;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hA) {
        for(int i = 0;i<edges.size();i++){
            int a= edges[i][0];
            int b = edges[i][1];
            tr[a].push_back(b);
            tr[b].push_back(a);
        }
        solve(0,-1,hA);
        return ans;
        
        
        
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<vector<int>>& graph, vector<int> temp){
        if(i==graph.size()-1){
            temp.push_back(graph.size()-1);
            ans.push_back(temp);
            return;
        }
        temp.push_back(i);
        for(int j:graph[i]){
            solve(j,graph,temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        solve(0,graph,vector<int>());
        return ans;
    }
};
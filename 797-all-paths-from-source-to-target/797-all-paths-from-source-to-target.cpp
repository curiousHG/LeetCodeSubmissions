class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<vector<int>>& graph, vector<int>& temp){
        if(i==graph.size()-1){
            ans.push_back(temp);
            return;
        }
        
        for(int j:graph[i]){
            temp.push_back(j);
            solve(j,graph,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp = {0};
        solve(0,graph,temp);
        return ans;
    }
};
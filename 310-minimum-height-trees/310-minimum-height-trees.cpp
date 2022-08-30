class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==2)return {0,1};
        vector<int> in(n, 0);
        vector<vector<int>> gr(n, vector<int>());
        for(auto &e:edges){
            in[e[0]]++;
            in[e[1]]++;
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i =0;i<in.size();i++){
            if(in[i]==1)q.push(i);
        }
        int k = n-1;
        while(!q.empty() && k>1){
            int s = q.size();
            for(int i= 0;i<s;i++){
                int t = q.front();
                in[t]--;
                q.pop();
                
                for(int j:gr[t]){
                    if(in[j]>1){
                        in[j]--;
                        k--;
                    }
                    if(in[j]==1)q.push(j);
                }
            }
            
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        if(ans[0]==ans[1])ans.pop_back();
        return ans;
    }
};
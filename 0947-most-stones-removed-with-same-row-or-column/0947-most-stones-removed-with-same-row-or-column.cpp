#define pii pair<int,int>
class Solution {
public:
    unordered_map<int,vector<int>> xs,ys;
    unordered_map<int,int> cot;
    void dfs(int i, vector<int> &arr,vector<vector<int>>& st,int c){
        if(arr[i]!=-1)return;
        int x = st[i][0],y = st[i][1];
        arr[i] = c;
        cot[c]++;
        for(int j:xs[x]){
            dfs(j,arr,st,c);
        }
        for(int j:ys[y]){
            dfs(j,arr,st,c);
        }
        
        
    }
    int removeStones(vector<vector<int>>& st) {
        int ans = 0,n = st.size();
        for(int i = 0;i<n;i++){
            xs[st[i][0]].push_back(i);
            ys[st[i][1]].push_back(i);
        }
        vector<int> arr(n, -1);
        int c = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]==-1){
                dfs(i,arr,st,c++);
                ans+=cot[c-1]-1;
            }
        }
        
        
        return ans;
    }
};
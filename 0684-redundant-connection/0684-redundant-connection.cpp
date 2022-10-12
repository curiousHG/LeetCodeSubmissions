class Solution {
public:
    int parent(int x, vector<int> &p){
        if(p[x]==-1)return x;
        return p[x] = parent(p[x], p);
    }
    void uni(int x, int y, vector<int>& p){
        int px = parent(x,p);
        int py = parent(y,p);
        if(px!=py){
            p[px] = py;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2,0);
        int n = edges.size();
        vector<int> p(n+1, -1);
        for(int i = 0;i<n;i++){
            int a = edges[i][0],b = edges[i][1];
            int pa,pb;
            pa = parent(a, p);
            pb = parent(b, p);
            if(pa==pb){
                ans[0] = a;ans[1] = b;
            }else{
                uni(pa, pb, p);
            }
        }
        return ans;
        
    }
};
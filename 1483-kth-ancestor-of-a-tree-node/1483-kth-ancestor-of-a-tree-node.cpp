class TreeAncestor {
public:
    vector<unordered_map<int,int>>pj;
    vector<bool> vis;
    void solve(int i, vector<int>& p){
        if(vis[i])return;
        vis[i] = true;
        pj[i][1] = p[i];
        int j = 1;
        int parej = pj[i][1<<(j-1)];
        if(parej!=-1){
            if(!vis[parej])solve(parej, p);
        }
        while(parej!=-1 && pj[parej].find(1<<(j-1))!=pj[parej].end()){
            pj[i][1<<j] = pj[parej][1<<(j-1)];
            parej = pj[i][1<<j];
            j++;
        }
        
    }
    TreeAncestor(int n, vector<int>& p) {
        vis.resize(n, false);
        pj.resize(n,unordered_map<int,int>());
        for(int i = 0;i<n;i++){
            solve(i, p);
        }
        // for(int i = 0;i<n;i++){
        //     cout<<i<<"->";
        //     for(auto& x:pj[i]){
        //         cout<<x.first<<" "<<x.second<<"|";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
    }
    
    int getKthAncestor(int node, int k) {
        int n = node;
        int i = 0;
        while(k && n!=-1){
            if(k&1<<i){
                k-=1<<i;
                if(pj[n].find(1<<i)!=pj[n].end()){
                    n = pj[n][1<<i];
                }else{
                    n = -1;
                }
                // cout<<(1<<i)<<" "<<n<<"|";
            }
            i++;
        }
        // cout<<endl;
        return n;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
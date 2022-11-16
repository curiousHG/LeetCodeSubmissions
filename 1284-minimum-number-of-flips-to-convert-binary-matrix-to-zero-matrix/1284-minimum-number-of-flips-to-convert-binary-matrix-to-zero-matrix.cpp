class Solution {
public:
    string ser(vector<vector<int>>& mat){
        string ans = "";
        int n = mat.size(),m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==1)ans+='1';
                else ans+='0';
            }
        }
        return ans;
    }
    vector<vector<int>> flip(int i, int j,vector<vector<int>> mat){
        int di[5] = {0,1,0,-1,0};
        int dj[5] = {0,0,1,0,-1};
        int n = mat.size(),m = mat[0].size();
        for(int k = 0;k<5;k++){
            int x = i+di[k];
            int y = j+dj[k];
            if(x<n && y<m && x>=0 && y>=0){
                if(mat[x][y])mat[x][y] = 0;
                else mat[x][y] = 1;
            }
        }
        return mat;
    }
    int minFlips(vector<vector<int>>& mat) {
        unordered_map<string, int> dis;
        int n = mat.size(),m = mat[0].size();
        string targ = string(n*m,'0');
        dis[targ] = INT_MAX;
        queue<vector<vector<int>>> q;
        q.push(mat);
        dis[ser(mat)] = 0;
        while(!q.empty()){
            vector<vector<int>> t = q.front();
            string s = ser(t);
            q.pop();
            // cout<<s<<" "<<dis[s]<<endl;
            
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    vector<vector<int>> nex = flip(i,j,t);
                    string se = ser(nex);
                    // cout<<se<<endl;
                    if(dis.find(se)==dis.end()){
                        dis[se]=INT_MAX;
                    }
                    if(dis[se]>dis[s]+1){
                        dis[se]=dis[s]+1;
                        q.push(nex);
                    }
                    
                }
            }
            
        }
        
        
        if(dis[targ]==INT_MAX)return -1;
        return dis[targ];
        
    }
};
#define pii pair<int,int>
#define f first
#define s second
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        unordered_map<int, vector<pii>> gr;
        for(int i = 0;i<fl.size();i++){
            if(gr.find(fl[i][0])==gr.end())gr[fl[i][0]] = vector<pii>();
            gr[fl[i][0]].push_back(make_pair(fl[i][1],fl[i][2]));
        }
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        queue<int> pq;
        pq.push(src);
        while(!pq.empty() && k>=0){
            int n = pq.size();
            vector<int> cur(dis);
            for(int i = 0;i<n;i++){
                int temp = pq.front();
                pq.pop();
                // cout<<temp<<"->";
                for(auto& next:gr[temp]){
                    if(cur[next.f]>dis[temp]+next.s){
                        cur[next.f]=dis[temp]+next.s;
                        pq.push(next.f);
                        // cout<<next.f<<" ";
                    }
                }
                cout<<endl;
            }
            dis = cur;
            k--;
            
        }
        return dis[dst]==INT_MAX?-1:dis[dst];

        
    }
};
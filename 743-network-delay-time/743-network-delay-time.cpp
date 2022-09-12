#define pii pair<int,int>
bool operator<(const pii& a, const pii& b){
    return a.first>b.first;
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1, INT_MAX);
        vector<vector<pii>> gr(n+1, vector<pii>());
        for(int i = 0;i<times.size();i++){
            int u = times[i][0],v = times[i][1],w = times[i][2];
            gr[u].push_back(make_pair(v, w));
        }
        priority_queue<pii> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            pii f = pq.top();
            pq.pop();
            for(pii n:gr[f.second]){
                if(dis[n.first]>n.second+f.first){
                    dis[n.first] = n.second+f.first;
                    pq.push({dis[n.first], n.first});
                }
            }
        }
        int mini = 0;
        for(int i= 1;i<=n;i++){
            if(dis[i]==INT_MAX)return -1;
            mini = max(mini, dis[i]);
        }
        return mini;
    }
};
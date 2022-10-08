// static const auto init = []{
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     return false;
// }();
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& po, int k) {
        // sort(points.begin(), points.end(), [](const auto& a, const auto& b){
        //     return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
        // });
        vector<vector<int>> ans;
        // for(int i = 0;i<k;i++){
        //     ans.push_back(points[i]);
        // }
        // return ans;
        int n = po.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            int x = po[i][0],y = po[i][1];
            int dis = x*x + y*y;
            pq.push({-dis, i});
        }
        for(int i = 0;i<k;i++){
            ans.push_back(po[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
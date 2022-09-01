static const auto init = []{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    return false;
}();
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto& a, auto& b){
            return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
        });
        vector<vector<int>> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(points[i]);
        }
        return ans;
        
    }
};
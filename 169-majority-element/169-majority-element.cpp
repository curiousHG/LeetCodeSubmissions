class Solution {
public:
    int majorityElement(vector<int>& v) {
        sort(v.begin(),v.end());
        return v[v.size()/2];
    }
};
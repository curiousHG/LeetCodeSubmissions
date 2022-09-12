class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(),[&](int a, int b){
            int c = abs(a-x),d = abs(b-x);
            if(c==d)return a<b; 
            return c<d;
        });
        vector<int> ans(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
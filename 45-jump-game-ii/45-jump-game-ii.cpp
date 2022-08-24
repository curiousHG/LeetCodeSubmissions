class Solution {
public:
    int jump(vector<int>& v) {
        int pmax = 0,tmax = 0, n = v.size(),step = 0;
        for(int i = 0;i<n-1;i++){
            pmax = max(pmax, i+v[i]);
            if(tmax==i){
                step++;
                tmax = pmax;
            }
        }
        return step;
    }
};
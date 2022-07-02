class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int n = hc.size(),m = vc.size();
        int mod = 1e9+7;
        hc.push_back(h);
        vc.push_back(w);
        hc.push_back(0);
        vc.push_back(0);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int h_max = 0,v_max = 0;
        for(int i = 0;i<=n;i++){
            h_max = max(h_max,hc[i+1]-hc[i]);
        }
        for(int i = 0;i<=m;i++){
            v_max = max(v_max,vc[i+1]-vc[i]);
        }
        
        return (long)h_max * v_max % mod;;
    }
};
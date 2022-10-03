class Solution {
public:
    int minCost(string col, vector<int>& nT) {
        int n = col.length();
        int l = 0,r = 0;
        int ans = 0;
        while(l<n && r<n){
            int maxi = 0,sum = 0;
            r = l;
            while(r<n && col[l]==col[r]){
                maxi = max(maxi, nT[r]);
                sum+=nT[r];
                r++;
            }
            if(r-l>0){
                ans+=sum-maxi;
                l = r;
            }else{
                l++;
            }
        }
        return ans;
    }
};
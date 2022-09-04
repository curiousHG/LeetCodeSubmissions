class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int g = 0,n = pr.size();
        for(int i = 0;i<n-1;i++){
            if(pr[i]<pr[i+1])g+=pr[i+1]-pr[i];
        }
        return g;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int maxi = -INT_MAX;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(sum<0){
                sum = 0;
            }
            sum+=v[i];
            if(maxi<sum){
                maxi = max(maxi,sum);
            } 
        }
        return maxi;
    }
};
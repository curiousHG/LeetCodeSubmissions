class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0};
        for(int i= 1;i<=n;i++){
            ans.push_back(ans[i/2]);
            if(i%2)ans[i]+=1;
        }
        return ans;
    }
};
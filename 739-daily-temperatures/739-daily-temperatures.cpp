class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        ans[n-1] = n;
        for(int i = n-2;i>-1;i--){
            int p = i+1;
            while(p<n && temp[i]>=temp[p])p = ans[p];
            ans[i] = p;
        }
        for(int i= 0;i<n;i++){
            if(ans[i]==n)ans[i] = 0;
            else ans[i] = ans[i]-i;
        }
        return ans;
        
        
    }
};
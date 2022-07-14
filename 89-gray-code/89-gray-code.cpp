class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n==0)return ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i = 2;i<=n;i++){
            vector<int> temp;
            for(int j= 0;j<ans.size();j++){
                if(j%2==0){
                    temp.push_back(ans[j]*2);
                    temp.push_back(ans[j]*2+1);
                }else{
                    temp.push_back(ans[j]*2+1);
                    temp.push_back(ans[j]*2);
                }
                
            }
            ans = temp;
        }
        return ans;
    }
};
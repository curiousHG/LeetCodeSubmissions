class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 1;i<=rowIndex+1;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 2;j<i;j++){
                temp.push_back(ans[j-2]+ans[j-1]);
            }
            if(i!=1)temp.push_back(1);
            ans = temp;
            
        }
        return ans;
    }
};
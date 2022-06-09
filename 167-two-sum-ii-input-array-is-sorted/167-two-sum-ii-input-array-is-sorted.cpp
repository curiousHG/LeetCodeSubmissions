class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int l = 0,r = v.size()-1;
        vector<int> ans;
        while(l<r){
            int sum = v[l]+v[r];
            if(sum<t)l++;
            else if(sum>t)r--;
            else{
                ans ={l+1,r+1};
                return ans;
            }
        }
        return ans;
        
    }
};
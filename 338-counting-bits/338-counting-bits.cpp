class Solution {
public:
    int count(int i){
        int a = 0;
        while(i){
            a+=i%2;
            i/=2;
        }
        return a;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i= 0;i<=n;i++)ans.push_back(count(i));
        return ans;
    }
};
class Solution {
public:
    vector<int> ans;
    void solve(int i, int j, int n, int k){
        if(j==n){
            ans.push_back(i);
            return;
        }
        int d = i%10;
        if(d+k<=9)solve(i*10+k+d,j+1,n,k);
        if(k==0)return;
        if(d-k>=0)solve(i*10+d-k,j+1,n,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1;i<=9;i++){
            solve(i, 1, n, k);
        }
        return ans;
    }
};
#define ll long long
class Solution {
public:
    vector<vector<ll>> memo;
    // vector<vector<int>> pos;
    ll dp(int i, int j,vector<int> &B){
        if(memo[i][j]!=-1)return memo[i][j];
        if(i==j||j==i+1)return 0;
        ll val = INT_MAX;
        ll l = B[j]-B[i];
        // cout<<B[i]<<" "<<B[j]<<endl;
        for(int k = i+1;k<j;k++){
            ll cost = l+dp(i, k,B)+dp(k, j,B);
            if(cost<val){
                val = cost;
            }
        }
        return memo[i][j] = val;

    }
    int minCost(int A, vector<int>& B) {
        int n = B.size();
        B.push_back(0);
        B.push_back(A);
        sort(B.begin(),B.end());
        memo.resize(n+2, vector<ll>(n+2,-1));
        return dp(0,n+1,B);
    }
};




class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<int> pre(n+1,0);
        for(int i =0;i<n;i++){
            pre[i+1] = (pre[i]+v[i])%k;
        }
        unordered_map<int,int>ss;
        for(int i = 0;i<=n;i++){
            if(ss.find(pre[i])!=ss.end()){
                if(i-ss[pre[i]]>1){
                    return true;
                }
            }
            if(ss.find(pre[i])!=ss.end())ss[pre[i]] = min(i, ss[pre[i]]);
            else ss[pre[i]] = i;
            cout<<ss[pre[i]]<<" ";
        }
        return false;
    }
};

/*
0 23 25 29 35 42
0  5  1  5  5  0
29 -6*k = 23

*/ 
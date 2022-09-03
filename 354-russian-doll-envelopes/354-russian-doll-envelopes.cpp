class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> lis;
        int n = env.size();
        for(int i = 0;i<n;i++){
            if(lis.size()==0)lis.push_back(env[i][1]);
            else if(lis.back()<env[i][1])lis.push_back(env[i][1]);
            else if(lis.front()>env[i][1])lis.front() = env[i][1];
            else{
                int ind = lower_bound(lis.begin(),lis.end(),env[i][1])-lis.begin();
                lis[ind] = env[i][1];
            }
        }
        return lis.size();
    }
};

/*
[3, 5]
[6, 10]
[6, 7]
[7, 13]
[7, 11]
[8, 4]


*/

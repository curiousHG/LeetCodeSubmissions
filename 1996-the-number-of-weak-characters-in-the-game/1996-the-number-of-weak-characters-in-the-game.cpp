class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pr) {
        sort(pr.begin(),pr.end(),[&](auto &a, auto &b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]>b[0];
        });
        int m = -INT_MAX,ans = 0,n = pr.size();
        for(int i = 0;i<n;i++){
            if(m>pr[i][1])ans++;
            else m = pr[i][1];
        }
        return ans;
        
    }
};

/*
6,3
5,5
3,6

10,4
4,3
4,4
*/

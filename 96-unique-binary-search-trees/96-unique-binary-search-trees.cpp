class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n+1,0);
        a[0] = 1;
        a[1] = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<i;j++){
                a[i]+=a[i-1-j]*a[j];
            }
        }
        return a[n];
        
    }
};
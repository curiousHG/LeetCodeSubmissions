class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length(),i= -1,j = 0,l,r,k = 0;
        vector<int> ans(n,0);
        while(j<n){
            while(j<n && s[j]!=c)j++;
            if(j==n)break;
            r = j;k = 0;
            if(i==-1){
                while(r>-1)ans[r--] = k++;
            }else{
                l=i;
                while(l<=r){
                    ans[l++] = k;
                    ans[r--] = k++;
                }
            }
            i = j;
            j++;
        }
        k = 0;
        while(i<n)ans[i++] = k++;
        return ans;
        
    }
};
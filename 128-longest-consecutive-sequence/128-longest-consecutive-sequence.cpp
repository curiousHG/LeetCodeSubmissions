class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        sort(v.begin(),v.end());
        int i = 0,n = v.size(),maxi = 0;
        if(n<2)return n;
        while(i<n){
            int j = i+1;
            int c = 0;
            while(j<n){
                if(v[j]==v[j-1]){
                    c++;
                    j++;
                }else if(v[j]==v[j-1]+1)j++;
                else break;
                
            }
            maxi = max(maxi, j-i-c);
            i = j;
        }
        return maxi;
        
        
    }
};
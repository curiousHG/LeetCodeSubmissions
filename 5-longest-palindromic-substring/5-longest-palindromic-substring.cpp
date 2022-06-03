class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        int n = s.length();
        int bestl = 0,bestr = 0;
        for(int i = 0;i<n;i++){
            int l = i-1,r = i+1,cur = 1;
            while(l>-1 && r<n){
                if(s[l]==s[r])cur+=2;
                else break;
                l--;r++;
            }
            if(maxi<cur){
                maxi = cur;
                bestl = ++l;
                bestr = --r;
            }
            l = i,r=i+1;
            cur = 0;
            while(l>-1 && r<n){
                if(s[l]==s[r])cur+=2;
                else break;
                l--;r++;
            }
            if(maxi<cur){
                maxi = cur;
                bestl = ++l;
                bestr = --r;
            }
            
        }
        cout<<bestl<<" "<<bestr<<endl;
        return s.substr(bestl,maxi);
    }
};
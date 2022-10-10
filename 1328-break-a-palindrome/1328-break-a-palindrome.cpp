class Solution {
public:
    string breakPalindrome(string palin) {
        string ans;
        int n = palin.length();
        if(n==1)return ans;
        for(int i = 0;i<n/2;i++){
            if(palin[i]!='a'){
                return palin.substr(0,i)+'a'+palin.substr(i+1);
            }
        }
        return palin.substr(0,n-1)+'b';
        
    }
};
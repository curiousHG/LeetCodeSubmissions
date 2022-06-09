class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string s = to_string(x);
        int n = s.length();
        for(int i = 0;i<n/2;i++){
            if(s[i]!=s[n-1-i])return false;
        }
        return true;
    }
};
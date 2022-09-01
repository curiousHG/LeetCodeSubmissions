class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(),i,j;
        j = n-1;
        string ans;
        while(j>=0 && i>=0){
            while(j>=0 && s[j]==' ')j--;
            i = j;
            while(i>=0 && s[i]!=' ')i--;
            ans=ans + s.substr(i+1, j-i);
            ans+=' ';
            j = i;
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;
    }
};
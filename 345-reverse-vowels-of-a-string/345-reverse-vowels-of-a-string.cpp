class Solution {
public:
    bool isVow(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return true;
        return false;
    }
    string reverseVowels(string s) {
        int i= 0,n = s.length(),j = n-1;
        while(i<j){
            if(isVow(s[i])&& isVow(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(!isVow(s[i])){
                i++;
            }else{
                j--;
            }
        }
        return s;
    }
};
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i]=='6'){
                string ans = s.substr(0,i)+"9"+s.substr(i+1);
                return stoi(ans);
            }
        }
        return num;
    }
    
};
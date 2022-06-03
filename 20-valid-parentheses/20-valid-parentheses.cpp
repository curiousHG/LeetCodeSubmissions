class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                st.push_back(s[i]);
            }else{
                if(st.size()<=0)return false;
                char p = st.back();
                st.pop_back();
                cout<<(int) s[i]<<" "<<(int)p<<endl;
                if(s[i]==']' && p == '[')continue;
                else if(s[i]=='}' && p == '{')continue;
                else if(s[i]==')' && p == '(')continue;
                else return false;
            }
        }
        if(!st.size())return true;
        return false;
    }
};
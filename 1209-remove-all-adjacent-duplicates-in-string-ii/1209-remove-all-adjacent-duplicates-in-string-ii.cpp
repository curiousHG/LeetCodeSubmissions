class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(make_pair(s[i],1));
            }else{
                pair<char,int> t = st.top();
                if(t.first!=s[i]){
                    st.push(make_pair(s[i],1));
                }else{
                    st.pop();
                    if(t.second+1<k)st.push(make_pair(s[i],t.second+1));
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            pair<char,int> t = st.top();
            ans=string(t.second, t.first)+ans;
            st.pop();
        }
        return ans;
        
        
    }
};
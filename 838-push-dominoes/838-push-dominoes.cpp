#define F first
#define S second
class Solution {
public:
    string pushDominoes(string domi) {
        int n = domi.length();
        vector<pair<char,int>> st;
        for(int i = 0;i<n;i++){
            if(domi[i]=='R')st.push_back({'R',i});
            else if(domi[i]=='L')st.push_back({'L',i});
        }
        string ans = "";
        if(st.size()==0)return domi;
        for(int i = 0;i<st.size();i++){
            if(i==0){
                ans+=string(st[i].S,st[i].F=='L'?'L':'.');
                ans+=string(1,st[i].F);
            }else{
                if(st[i-1].F==st[i].F){
                    ans+=string(st[i].S-st[i-1].S, st[i].F);
                }else if(st[i-1].F=='L' && st[i].F=='R'){
                        ans+=string(st[i].S-st[i-1].S-1, '.');
                        ans+='R';
                }else{
                    int mid = st[i].S-st[i-1].S-1;
                    ans+=string(mid/2, 'R');
                    if(mid%2)ans+='.';
                    ans+=string(mid/2+1,'L');
                }
            }
        }
        ans+=string(n-st.back().S-1,st.back().F=='R'?'R':'.');
        // ans+=string(1,st.back().F);
        
        return ans;
        
        
    }
};
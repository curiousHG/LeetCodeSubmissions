class Solution {
public:
    string minWindow(string s, string t) {
        int l = t.length(),i = 0,j = 0,n = s.length(), mini = INT_MAX;
        unordered_map<char,int> m;
        for(int i = 0;i<l;i++)m[t[i]]++;
        string ans;
        while(i<n && j<n){
            if(l>0){
                if(m.find(s[j])!=m.end()){
                    m[s[j]]--;
                    if(m[s[j]]>=0)l--;
                }
                j++;
            }else if(l==0){
                if(j-i<mini){
                    mini = j-i;
                    ans = s.substr(i, mini);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0)l++;  
                }
                i++;
            }
            // cout<<l<<" "<<i<<" "<<j<<" "<<s.substr(i,j-i)<<endl;
        }
        while(i<n && l==0){
            if(j-i<mini){
                mini = j-i;
                ans = s.substr(i, mini);
                cout<<ans<<endl;
            }
            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]>0)l++;  
            }
            i++;
            // cout<<l<<" "<<i<<" "<<j<<" "<<s.substr(i,j-i)<<endl;
        }
        return ans;
    }
};
class Solution {
public:
    void print(int c[26]){
        cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
    }
    vector<int> findAnagrams(string s, string p) {
        int c[26];
        vector<int> ans;
        memset(c, 0, sizeof(c));
        for(char i:p)c[i-'a']++;
        int i = 0,j = 0,l=p.length(),n = s.length();
        while(j<n){
            int v = s[j]-'a';
            if(c[v]>0){
                c[v]--;l--;j++;
                if(l==0)ans.push_back(i);
            }else{
                // while(i<j){
                //     c[s[i]-'a']++;l++;i++;
                // }
                c[s[i]-'a']++;l++;i++;
                // if(c[s[j]-'a']==0){i++;j++;}
            }
            // cout<<i<<" "<<j<<" "<<s.substr(i, j-i)<<endl;
            // print(c);
        }
        return ans;
        
    }
};
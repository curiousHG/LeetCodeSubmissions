class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            for(int j = 0;j<t.length();j++){
                if(s[i]==t[j])continue;
                int k = 1;
                int left = 0,right = 0;
                while(i-k>-1 && j-k>-1){
                    if(s[i-k]==t[j-k])left++;
                    else break;
                    k++;
                }
                k = 1;
                while(i+k<s.length() && j+k<t.length()){
                    if(s[i+k]==t[j+k])right++;
                    else break;
                    k++;
                }
                if(left==0 && right==0)ans++;
                else{
                    ans+=(left+1)*(right+1);
                }
            }
        }
        return ans;
    }
};
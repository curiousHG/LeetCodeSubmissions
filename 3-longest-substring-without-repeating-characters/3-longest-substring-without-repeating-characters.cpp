class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;
        int maxi = 0;
        int cur = 0;
        for(int i= 0;i<s.length();i++){
            if(last.find(s[i])==last.end()){
                cur++;
            }else{
                if(i-last[s[i]]>cur){
                    cur++;
                }else{
                    cur = i-last[s[i]];
                }
                
            }
            last[s[i]] = i;
            maxi = max(maxi,cur);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp(26,0);
        int n = words1.size(),m = words2.size();
        for(int i= 0;i<m;i++){
            vector<int> temp(26,0);
            for(char c:words2[i]){
                temp[c-'a']++;
            }
            for(int k =0;k<26;k++)mp[k] = max(mp[k],temp[k]);
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            vector<int> temp(26,0);
            for(char c:words1[i]){
                temp[c-'a']++;
            }
            bool poss = true;
            for(int k = 0;k<26;k++){
                if(temp[k]<mp[k])poss = false;
            }
            if(poss)ans.push_back(words1[i]);
        }
        return ans;
    }
};
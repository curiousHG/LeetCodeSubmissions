class Solution {
public:
    int maxi = 0;
    void recur(int j, vector<int> &avail, vector<string>& words,vector<int>& score, int sc){
        if(j==words.size()){
            maxi = max(maxi, sc);
            return;
        }
        
        int need[26] = {0};
        for(char c:words[j]){
            need[c-'a']++;
        }
        int cur = 0;
        bool poss = true;
        for(int i = 0;i<26;i++){
            if(need[i]<=avail[i]){
                cur+=need[i]*score[i];
            }else{
                poss = false;
            }
            avail[i]-=need[i];
        }
        if(poss){
            recur(j+1, avail, words, score, sc+cur);
        }
        for(int i = 0;i<26;i++){
            avail[i]+=need[i];
        }
        recur(j+1, avail, words, score, sc);

    }
    int maxScoreWords(vector<string>& words, vector<char>& let, vector<int>& score) {
        vector<int> avail(26,0);
        for(char c:let){
            avail[c-'a']++;
        }
        recur(0,avail,words,score,0);
        return maxi;

        
    }
};
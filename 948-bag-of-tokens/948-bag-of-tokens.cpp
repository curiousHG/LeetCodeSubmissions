class Solution {
public:
    int bagOfTokensScore(vector<int>& to, int pow) {
        sort(to.begin(),to.end());
        int n = to.size(),i = 0,j = n-1,sc = 0, maxi = 0;
        while(i<=j){
            if(to[i]<=pow){
                pow-=to[i];
                sc++;
                maxi = max(maxi,sc);
                i++;
            }else if(sc>0){
                sc--;
                pow+=to[j];
                j--;
            }else break;
        }
        return maxi;
        
    }
};
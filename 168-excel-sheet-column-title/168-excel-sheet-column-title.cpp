class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        while(c){
            int k = c%26;
            if(k==0)k+=26;
            char t = 'A'+k-1;
            c-=k;
            s = t+s;
            c = c/26;
        }
        return s;
    }
};
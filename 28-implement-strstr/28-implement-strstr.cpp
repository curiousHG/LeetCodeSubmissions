class Solution {
public:
    int strStr(string h, string ne) {
        for(int i = 0;i<h.length();i++){
            if(i+ne.length()>h.length())return -1;
            bool f =true;
            for(int j = 0;j<ne.length()&&f;j++){
                if(h[i+j]!=ne[j])f = false;
            }
            if(f)return i;
        }
        return -1;
    }
};
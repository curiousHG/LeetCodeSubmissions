class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> c;
        int i= 0;
        while(i<s.length()){
            if(c.size()==0){
                c.push_back(s[i]);
            }else{
                if(c.back()==s[i])c.pop_back();
                else c.push_back(s[i]);
            }
            i++;
        }
        string ans;
        for(char l:c)ans+=l;
        return ans;
    }
};
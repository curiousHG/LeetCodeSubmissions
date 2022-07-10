class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            string temp = to_string(n);
            int val = 0,k;
            for(int i = 0;i<temp.length();i++){
                k = temp[i]-'0';
                val+=k*k;
            }
            n = val;
            
        }
        return n==1;
        
    }
};
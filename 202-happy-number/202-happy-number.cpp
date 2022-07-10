class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            int val = 0,k;
            while(n){
                k = n%10;
                val+=k*k;
                n = n/10;
            }
            n = val;
            
        }
        return n==1;
        
    }
};
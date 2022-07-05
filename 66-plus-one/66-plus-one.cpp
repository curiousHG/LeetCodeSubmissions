class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        bool carry = false;
        while(i>-1){
            if(digits[i]+1<10){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
                i--;
                carry = true;
            }
        }
        vector<int> v;
        if(carry)v.push_back(1);
        for(int i = 0;i<n;i++)v.push_back(digits[i]);
        return v;
    }
};
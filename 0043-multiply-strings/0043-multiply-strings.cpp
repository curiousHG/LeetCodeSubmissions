class Solution {
public:
    void add(int i, int val, vector<int> &ans){
        while(val){
            ans[i]+=val%10;
            val/=10;
            val+=ans[i]/10;
            ans[i]%=10;
            i++;
        }
        // for(int i = ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
        // cout<<endl;
    }
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        vector<int> ans(n+m, 0);
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int val = (num1[i]-'0')*(num2[j]-'0');
                int s = n-1-i+m-1-j;
                add(s, val, ans);
            }
        }
        string ret = "";
        int i = n+m-1;
        while(i>=0 && ans[i]==0)i--;
        for(;i>=0;i--)ret+=ans[i]+'0';
        if(ret=="")ret = "0";
        return ret;
        
    }
};
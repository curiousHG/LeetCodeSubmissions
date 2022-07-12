class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int carry = 0;
        int i = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = min(a.length(),b.length());
        while(i<n){
            if(a[i]==b[i]){
                if(a[i]=='1'){
                    if(carry) c+='1';
                    else c+='0';
                    carry = 1;
                }else{
                    if(carry){
                        c+='1';
                        carry = 0;
                    }else c+='0';
                }
            }else{
                if(carry){
                    c+='0';
                }else{
                    c+='1';
                }
                
            }
            i++;
        }
        while(i<a.length()){
            if(a[i]=='1'){
                if(carry){
                    c+='0';
                }else{
                    c+='1';
                }
            }else{
                if(carry){
                    c+='1';
                    carry = 0;
                }else{
                    c+='0';
                }
            }
            i++;
        }
        while(i<b.length()){
            if(b[i]=='1'){
                if(carry){
                    c+='0';
                }else{
                    c+='1';
                }
            }else{
                if(carry){
                    c+='1';
                    carry = 0;
                }else{
                    c+='0';
                }
            }
            i++;
        }
        if(carry)c+='1';
        reverse(c.begin(),c.end());
        return c;
    }
};
void qqe(vector<int> &a){
    cout<<a.size()<<"->";
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<"|";
}
void qqr(vector<string> &b){
    cout<<b.size()<<"->";
    for(string tr:b){
        cout<<tr<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    string decodeString(string s) {
        int i = 0,n = s.length(), v = 0,num = 0;
        int l,r;
        string ans = "";
        while(i<n){
            if(s[i]-'0'<=9 && s[i]-'0'>=0){
                while(i<n && s[i]-'0'<=9 && s[i]-'0'>=0){
                    num = num*10+s[i]-'0';
                    i++;
                }
                v++;
                i++;
                l = i;
                while(i<n && v){
                    if(s[i]=='[')v++;
                    else if(s[i]==']')v--;
                    i++;
                }
                r = i-1;
                string sub = s.substr(l, r-l);
                // cout<<sub<<endl;
                string temp = decodeString(sub);
                for(int i = 0;i<num;i++){
                    ans+=temp;
                }
                num=0;
                i--;
                
            }else{
                ans+=s[i];
            }
            
            i++;
        }
        return ans;
    }
};
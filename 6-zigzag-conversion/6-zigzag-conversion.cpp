class Solution {
public:
    string convert(string s, int numr) {
        int n = s.length();
        if(numr==1)return s;
        int i = 0,j = 0,d = 1;
        vector<string> ans(numr);
        int k = 0;
        while(k<n){
            if(d==1){
                if(i==numr){
                    d=-1;
                    i = numr-2;
                    continue;
                }
                ans[i]+= s[k];
                i++;
                
            }else if(d==-1){
                if(i==0){
                    d = 1;
                    continue;
                }
                ans[i]+= s[k];
                i--;
                
            }
            k++;
        }
        string f = "";
        for(int i = 0;i<numr;i++){
            cout<<ans[i]<<endl;
            f+=ans[i];
        }
        
        return f;
    }
};
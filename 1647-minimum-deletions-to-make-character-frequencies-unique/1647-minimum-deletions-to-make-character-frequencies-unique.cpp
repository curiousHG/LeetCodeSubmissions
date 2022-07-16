class Solution {
public:
    int minDeletions(string s) {
        int a[26] = {};
        for(char c:s){
            a[c-'a']++;
        }
        // for(int i:a)cout<<i<<" ";
        sort(a, a+26);
        int ans = 0;
        for(int j = 24;j>=0;j--){
            
            if(a[j]==0)break;
            if(a[j+1]<a[j]){
                ans+=a[j]-a[j+1];
                a[j] = a[j+1];
            }
            if(a[j+1]==a[j] && a[j]!=0){
                a[j]--;
                ans++;
            }
            // for(int i:a)cout<<i<<" ";
            cout<<endl;
        }
        return ans;
    }
};
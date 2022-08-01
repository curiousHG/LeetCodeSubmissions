class Solution {
public:
    int findComplement(int num) {
        int x= num,c = 0,ans = 0,i = 0;
        while(x){
            x>>=1;
            c++;
        }
        
        while(c--){
            if(num%2==0){
                ans+=1<<i;
            }
            i++;
            num>>=1;
        }
        // cout<<c<<" "<<i<<endl;
        return ans;
    }
};
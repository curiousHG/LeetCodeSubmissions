class Solution {
public:
    int candy(vector<int>& rat) {
        int n= rat.size();
        vector<int> can(n,1);
        for(int i = 1;i<n;i++){
            if(rat[i]>rat[i-1]){
                can[i] = can[i-1]+1;
            }
        }
        // for(int i= 0;i<n;i++)cout<<can[i]<<" ";cout<<endl;
        for(int i= n-2;i>=0;i--){
            if(rat[i]>rat[i+1]){
                can[i]=max(can[i],can[i+1]+1);
            }
        }
        // for(int i= 0;i<n;i++)cout<<can[i]<<" ";cout<<endl;
        int sum = 0;
        for(int i= 0;i<n;i++){
            sum+=can[i];
        }
        
        return sum;
        
        
    }
};
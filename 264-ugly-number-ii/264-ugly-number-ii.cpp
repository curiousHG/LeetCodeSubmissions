class Solution {
public:
    int nthUglyNumber(int n) {
        int p1 = 0,p2 = 0,p3 = 0;
        vector<int> arr = {1};
        int k = n-1;
        while(k){
            int val = min(arr[p1]*2,min(arr[p2]*3, arr[p3]*5));            
            if(val==arr[p1]*2){
                p1++;
            }else if(val==arr[p2]*3){
                p2++;
            }else{
                p3++;
            }
            if(val==arr.back())continue;
            // cout<<val<<" ";
            arr.push_back(val);
            k--;
        }
        return arr[n-1];
        
    }
};

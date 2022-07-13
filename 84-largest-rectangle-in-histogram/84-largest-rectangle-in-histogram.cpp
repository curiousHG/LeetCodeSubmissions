class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(),i = 1,j = n-2,maxi = 0;
        vector<int> right(n),left(n);
        left[0]=-1;right[n-1] = n;
        while(i<n){
            int p = i-1;
            while(p>=0 && h[p]>=h[i]){
                p = left[p];
            }
            left[i] = p;
            i++;
        }
        while(j>-1){
            int p = j+1;
            while(p<n && h[p]>=h[j])p=right[p];
            right[j] = p;
            j--;
        }
        for(int i = 0;i<n;i++){
            int l = right[i]-left[i]-1;
            maxi = max(maxi, h[i]*l);
            
        }
        return maxi;
        
    }
};
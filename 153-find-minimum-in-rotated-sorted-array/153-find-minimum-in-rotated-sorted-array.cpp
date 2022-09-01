class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0,h = n-1,mid;
        while(l<h){
            mid = (l+h)/2;
            if(mid>0 && a[mid-1]>a[mid]){h = mid;break;}
            if(a[mid]<a[h]){
                h =mid-1;
            }else{
                l = mid+1;
            }
        }
        if(h>=0)return min(a[0], a[h]);
        return a[0];
    }
};
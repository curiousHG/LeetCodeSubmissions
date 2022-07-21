class Solution {
public:
    bool test(vector<int>& w, int size,int t){
        int i = 0,c= 1,sum=0,n = w.size();
        while(i<n){
            if(size<w[i]){
                c = INT_MAX;
                break;
            }
            if(sum+w[i]<=size){
                sum+=w[i];
                i++;
            }else{
                c++;
                sum = 0;
            }
        }
        if(c>t){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size(),l = 0,r = 0,mid;
        for(int i= 0;i<n;i++)r+=w[i];
        while(l<r){
            mid = (l+r)/2;
            bool k = test(w,mid, days);
            // cout<<mid<<" "<<k<<endl;
            // if(c==days)return mid;
            if(k){
                r = mid;
            }else{
                l = mid;
            }
            if(l+1==r)break;
        }
        if(test(w, l,days))return l;
        return r;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> l,r;
        int n = h.size();
        int i = 1;
        int l_max = h[0];
        int r_max = h[n-1];
        l.push_back(l_max);
        r.push_back(r_max);
        while(i<n){
            l_max = max(l_max, h[i]);
            r_max = max(r_max, h[n-1-i]);
            l.push_back(l_max);
            r.push_back(r_max);
            i++;
        }
        for(int i = 0;i<l.size();i++)cout<<l[i]<<" ";
        cout<<endl;
        for(int i = 0;i<l.size();i++)cout<<r[i]<<" ";
        cout<<endl;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+=min(l[i],r[n-1-i])-h[i];
        }
        return ans;
    }
};
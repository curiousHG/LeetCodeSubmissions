#define ll long long
#define pii pair<int,int>

bool operator<(const pii& a, const pii &b){
    return a.first>b.first;
}

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        auto comp = [](const pii& a, const pii &b){
            return a.first>b.first;
        };
        int n = costs.size();
        int l = 0, h = n-1;
        priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
        while(l<=h && l<c && n-1-h<c){
            pq.push({costs[l], l});
            if(l<h)pq.push({costs[h], h});
            l++;
            h--;
        }
        l--;
        h++;
        ll ans= 0;
        for(int i = 0;i<k;i++){
            pii t = pq.top();
            int val = t.first;
            int ind = t.second;
            // cout<<val<<" "<<ind<<" "<<l<<" "<<h<<endl;
            pq.pop();
            if(ind>=h){
                h--;
                if(l<h)pq.push({costs[h], h});
            }else{
                l++;
                if(l<h)pq.push({costs[l], l});
            }
            ans+=val;
        }
        return ans;
        
    }
};
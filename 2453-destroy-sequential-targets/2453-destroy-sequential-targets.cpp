class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, vector<int>> mp;
        int maxi = 0, im = 0;
        for(int i:nums){
            mp[i%space].push_back(i);
        }
        int m = 0,ans = INT_MAX;
        for(auto it = mp.begin();it!=mp.end();it++){
            int v = (*it).first;
            vector<int> k = (*it).second;
            // cout<<v<<" "<<k.size()<<endl;
            if(k.size()>m)ans = INT_MAX;
            if(k.size()>=m){
                m = k.size();
                for(int i:k)ans = min(ans, i);
            }
        }
        return ans;
    }
};
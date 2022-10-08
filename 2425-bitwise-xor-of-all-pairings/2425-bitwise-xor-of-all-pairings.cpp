#define ll long long
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll, ll>mp;
        int n = nums1.size(),m = nums2.size();
        for(int i = 0;i<n;i++){
            mp[nums1[i]]+=m;
        }
        for(int i = 0;i<m;i++){
            mp[nums2[i]]+=n;
        }
        ll ans = 0;
        for(auto& [key,val]:mp){
            if(val%2){
                ans^=key;
            }
        }
        return ans;
    }
};
/*
2 - 4
1 - 4
3 - 4
10 - 3

*/  
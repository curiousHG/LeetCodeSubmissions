class Solution {        
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i])==m.end())m[nums[i]] = 0;
            m[nums[i]]++;
            
        }
        
        vector<pair<int,int>> temp;
        for(auto& it:m){
            temp.push_back(make_pair(it.first,it.second));
        }
        auto cmp = [&](pair<int,int> &a, pair<int,int> &b)-> bool {
            return a.second>b.second;
        };
        sort(temp.begin(),temp.end(),cmp);
        vector<int> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
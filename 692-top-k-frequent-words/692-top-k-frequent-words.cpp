class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto s:words){
            mp[s]++;
        }
        vector<pair<int, string>> temp;
        for(auto p:mp){
            temp.push_back({p.second, p.first});
        }
        sort(temp.begin(),temp.end(), [](auto &a, auto &b){
            if(a.first==b.first){
                return lexicographical_compare(a.second.begin(),a.second.end(), b.second.begin(),b.second.end());
            }
            return a.first>b.first;
        });
        vector<string> ans;
        for(int i= 0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
        
        
    }
};
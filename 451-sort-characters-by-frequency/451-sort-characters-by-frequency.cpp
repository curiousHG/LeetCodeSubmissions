class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(char c:s){
            if(m.find(c)==m.end())m[c] = 0;
            m[c]++;
        }
        string ans = "";
        vector<pair<int,char>> d;
        for(auto it = m.begin();it!=m.end();++it){
            d.push_back(make_pair(it->second, it->first));
        }
        // sort(d.begin().d.end(),[&](pair<int,char> a, pair<int,char> b){
        //     a.first>b.first;
        // });
        sort(d.begin(),d.end(),[&](pair<int,char> &a, pair<int,char> &b){
            return a.first>b.first;
        });
        for(int i = 0;i<d.size();i++){
            ans+=string(d[i].first,d[i].second);
        }
        return ans;
        
        
    }
};
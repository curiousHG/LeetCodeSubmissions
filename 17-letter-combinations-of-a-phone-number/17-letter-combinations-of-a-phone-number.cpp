class Solution {
public:
    unordered_map<int,vector<char>> m;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        m[2] = {'a','b','c'};
        m[3] = {'d','e','f'};
        m[4] = {'g','h','i'};
        m[5] = {'j','k','l'};
        m[6] = {'m','n','o'};
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};
        if(digits.length()==0)return ans;
        solve(digits, "",0);
        return ans;
        
    }
    void solve(string digits, string cur,int i){
        if(i==digits.length()){
            ans.push_back(cur);
        }else{
            for(int j = 0;j<m[digits[i]-'0'].size();j++){
                solve(digits, cur+m[digits[i]-'0'][j],i+1);
            }
        }
    }
    
};
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        recur(0,n,"",n);
        return ans;
    }
    void recur(int i,int n,string curr, int r){
        if(i==n){
            for(int i = 0;i<r;i++)curr+=')';
            // cout<<curr<<endl;
            ans.push_back(curr);
        }else{
            recur(i+1,n,curr+'(',r);
            if(i>n-r)recur(i,n,curr+')',r-1);
        }
        
    }
};
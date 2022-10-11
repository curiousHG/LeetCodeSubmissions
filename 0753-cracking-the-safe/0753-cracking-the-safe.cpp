class Solution {
public:
    unordered_set<string> ans;
    string f;
    bool recur(int i, int n, int k, string temp){
        if(ans.size()==pow(k,n)){
            f =temp;
            return true;
        }
        string sub = temp.substr(i-n+1,n-1);
        for(int j = 0;j<k;j++){
            char c = '0'+j;
            if(ans.find(sub+c)==ans.end()){
                ans.insert(sub+c);
                if (recur(i+1, n, k, temp+c))return true;
                ans.erase(sub+c);
            }
        }
        return false;

    }
    string crackSafe(int n, int k) {
        string temp = string(n,'0');
        ans.insert(temp);
        recur(n, n, k, temp);
        return f;
        
    }
};
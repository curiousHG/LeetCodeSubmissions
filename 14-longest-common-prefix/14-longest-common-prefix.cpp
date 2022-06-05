class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1;i<strs.size();i++){
            int j = 0;
            if(strs[i]=="")return "";
            while(j<strs[i].length() && j<ans.length()){
                if(strs[i][j]!=ans[j]){
                    ans = strs[i].substr(0,j);
                    cout<<ans<<endl;
                    break;
                }
                j++;
                if(j==strs[i].length())ans = strs[i];
            }
        }
        return ans;
    }
};
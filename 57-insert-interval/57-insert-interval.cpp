class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& nInt) {
        vector<vector<int>> ans;
        int i= 0,n = inte.size();
        while(i<n && inte[i][1]<nInt[0])ans.push_back(inte[i++]);
        int j = i;
        while(j<n && inte[j][0]<=nInt[1])j++;
        if(i==j){
            ans.push_back(nInt);
        }else{
            ans.push_back({min(inte[i][0],nInt[0]),max(nInt[1],inte[j-1][1])});
        }
        while(j<n && inte[j][0]>nInt[1])ans.push_back(inte[j++]);
        
        return ans;
        /*
        4 5
        
        1 5
        6 7
        
        */
    }
};
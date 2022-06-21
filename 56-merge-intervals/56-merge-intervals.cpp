class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
            });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0])ans.push_back(intervals[i]);
            else if(ans.back()[1]==intervals[i][0])ans.back()[1] = intervals[i][1];
            else{
                if(ans.back()[1]<intervals[i][1])ans.back()[1] = intervals[i][1];
            }
        }
        return ans;
    }
};
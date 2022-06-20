class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = p[0];
        int prof = 0;
        for(int i:p){
            prof = max(prof, i-mini);
            mini = min(i,mini);
        }
        return prof;
    }
};
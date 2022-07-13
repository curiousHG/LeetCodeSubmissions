class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> ind;
        int n = nums.size();
        for(int i= 0;i<k;i++){
            while(ind.size()>0 && nums[ind.back()]<nums[i]){
                ind.pop_back();
            }
            ind.push_back(i);
        }
        vector<int> ans;
        for(int i= k;i<n;i++){
            ans.push_back(nums[ind.front()]);
            if(ind.front()+k<=i)ind.pop_front();
            while(ind.size()>0 && nums[ind.back()]<nums[i]){
                ind.pop_back();
            }
            ind.push_back(i);
        }
        ans.push_back(nums[ind.front()]);
        return ans;
    }
};
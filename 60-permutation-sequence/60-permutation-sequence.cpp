class Solution {
public:
    vector<int> fact;
    string getPermutation(int n, int k) {
        fact.push_back(1);
        vector<int> nums;
        for(int i = 1;i<=n;i++){
            fact.push_back(fact.back()*i);
            nums.push_back(i);
        }
        int i = 0;
        string ans = "";
        while(k){
            int val = fact[n-1-i];
            if(k==fact[n-i]){
                for(int i = nums.size()-1;i>=0;i--)ans+=(nums[i]+'0');
                break;
            }
            if(k<val){
                ans+=nums.front()+'0';
                nums.erase(nums.begin());
            }else if(k%val==0){
                int ind  = k/val -1;
                ans+=nums[ind]+'0';
                nums.erase(nums.begin()+ind);
                k = val;
            }else if(k>val){
                int ind = nums[k/val];
                ans+=ind+'0';
                nums.erase(nums.begin()+k/val);
                k%=val;
            }
            i++;
        }
        return ans;
        
        
    }
};
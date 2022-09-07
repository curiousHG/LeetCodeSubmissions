class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> ns;
        for(int i = 0;i<nums.size();i++){
            ns.push_back(to_string(nums[i]));
        }
        sort(ns.begin(), ns.end(),[](string &a,string &b){
            string c = a+b;
            string d = b+a;
            for(int i = 0;i<c.size();i++){
                if(c[i]>d[i]){
                    return true;
                }else if(c[i]<d[i]){
                    return false;
                }
            }
            return false;
        });
        string ans = "";
        for(int i = 0;i<ns.size();i++){
            if(ans=="" && ns[i]=="0")continue;
            ans+=ns[i];
        }
        if(ans=="")ans = "0";
        
        return ans;
    }
};
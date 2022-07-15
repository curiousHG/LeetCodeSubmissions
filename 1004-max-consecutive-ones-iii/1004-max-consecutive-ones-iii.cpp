class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0,j =0,n = nums.size(),maxi = 0, count = 0;
        int c = k;
        while(j<n){
            while(j<n){
                if(nums[j]==0){
                    if(c>0)c--;
                    else break;
                }
                count++;
                maxi = max(maxi, count);
                j++;
                // cout<<i<<" "<<j<<" "<<count<<" "<<maxi<<" "<<c<<endl;
            }
            while(i<n){
                if(nums[i]==1){
                    count--;
                    i++;
                    continue;
                }
                if(c<k){
                    c++;
                    count--;
                    i++;
                }else{
                    i++;
                    j = i;
                }
                break;
                // cout<<i<<" "<<j<<" "<<count<<" "<<maxi<<" "<<c<<endl;
            }
        }
        return maxi;
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = n;
        int j = 0;
        int c = n+m-1;
        for(int k = 0;k<m;k++){
            swap(nums1[m-1-k],nums1[c-k]);
        }
        // cout<<"OK"<<endl;
        int k = 0;
        while(i<m+n && j<n){
            // cout<<"OK"<<endl;
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums1[i];
                i++;
                k++;
            }else{
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(j<n){
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
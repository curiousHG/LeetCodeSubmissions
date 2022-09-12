class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> copy(arr);
        int i = 0,j = 0,n = arr.size();
        while(j<n){
            if(copy[i]!=0){
                arr[j] = copy[i];
                j++;
            }else{
                arr[j] = 0;
                if(j+1<n)arr[j+1] = 0;
                j+=2;
            }
            i++;
        }
        
    }
};
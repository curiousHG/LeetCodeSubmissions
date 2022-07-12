class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int n = gas.size();
        for(int i = 0;i<n;i++){
            diff.push_back(gas[i]-cost[i]);
        }
        int sum = 0,tank = 0,si = 0;
        for(int i = 0;i<n;i++)sum+=diff[i];
        if(sum<0)return -1;
        for(int i= 0;i<n;i++){
            tank+=diff[i];
            if(tank<=0){
                if(i!=n-1)si = i+1;
                tank = 0;
            }
        }
        int j = 0;
        while(j<si){
            tank+=diff[j];
            // cout<<tank<<" "<<j<<endl;
            if(tank<0)return -1;
            j++;
        }
        return si;
        
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0,tank = 0,si = 0;
        for(int i = 0;i<n;i++)sum+=gas[i]-cost[i];
        if(sum<0)return -1;
        for(int i= 0;i<n;i++){
            tank+=gas[i]-cost[i];
            if(tank<=0){
                if(i!=n-1)si = i+1;
                tank = 0;
            }
        }
        int j = 0;
        while(j<si){
            tank+=gas[j]-cost[j];
            if(tank<0)return -1;
            j++;
        }
        return si;
        
    }
};
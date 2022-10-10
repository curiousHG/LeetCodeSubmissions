#define F first
#define S second
class MyCalendarThree {
public:
    
    map<int,int> mp;
    MyCalendarThree() {
    }
    
    int book(int s, int e) {
        int maxi = 0,val = 0;
        mp[s]++;
        mp[e]--;
        for(auto it = mp.begin();it!=mp.end();it++){
            val+=(*it).second;
            maxi = max(maxi, val);
        }
        
        return maxi;
        
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
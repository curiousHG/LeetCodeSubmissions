class MyCalendar {
public:
    vector<pair<int,int>> cal;
    MyCalendar() {
    }
    
    bool book(int s, int e) {
        for(auto p:cal){
            if(e<=p.first || p.second<=s)continue;
            else return false;
        }
        cal.push_back(make_pair(s,e));
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
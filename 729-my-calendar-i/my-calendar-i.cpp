class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<vector<int>> bookings;
    bool book(int startTime, int endTime) {
        for (auto it : bookings) {
            if(max(it[0], startTime) < min(it[1] , endTime))
                return false ;
        }
        bookings.push_back({startTime, endTime});
        return true ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
class MyCalendar {
public:
    vector<vector<int>> meetings;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int n = meetings.size();
        if(n == 0){
            vector<int> temp;
            temp.push_back(startTime);
            temp.push_back(endTime);
            meetings.push_back(temp);
            return true;
        }
        for(auto meeting : meetings){
            if((startTime >= meeting[0] && startTime < meeting[1]) || (endTime > meeting[0] && endTime <= meeting[1]) || (endTime > meeting[1] && startTime <= meeting[0])){
                return false;
            }
        }
        vector<int> temp;
        temp.push_back(startTime);
        temp.push_back(endTime);
        meetings.push_back(temp);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
class MyCalendar {
public:
    vector<vector<int>> calander;
    MyCalendar() {
        // vector<vector<int>> calander;
    }
    
    bool book(int start, int end) {
        for(int i=0; i<calander.size(); i++)
        {
            // cout<<calander[i][0]<<" "<<calander[i][1]<<" "<<start<<" "<<end<<endl;
            if((calander[i][0]<end && calander[i][1]>start)) 
            {
                // cout<<calander[i][0]<<" "<<calander[i][1]<<" "<<start<<" "<<end<<endl;
                return false;
            }
                
        }
        vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            calander.push_back(temp);
            return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
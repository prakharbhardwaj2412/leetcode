class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        
        for(int i=0; i<students.size(); i++)
        {
            stu.push(students[i]);
        }
        int rotation=0, sandwich_i=0;
        
        while(stu.size()!=rotation)
        {
            if(stu.front()==sandwiches[sandwich_i])
            {
                stu.pop(); sandwich_i++;
                rotation=0;
            }
            else
            {
                int x=stu.front();
                stu.pop();
                stu.push(x);
                rotation++;
            }
        }
        
        return stu.size();
        
    }
};
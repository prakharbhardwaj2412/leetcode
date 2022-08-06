class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        
        for(int i=0; i<students.size(); i++)
        {
            stu.push(students[i]);
        }
        int rot=0, i=0;
        
        while(stu.size()!=rot)
        {
            if(stu.front()==sandwiches[i])
            {
                stu.pop(); i++;
                rot=0;
            }
            else
            {
                int x=stu.front();
                stu.pop();
                stu.push(x);
                rot++;
            }
        }
        
        return stu.size();
        
    }
};
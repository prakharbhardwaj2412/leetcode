class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu, san;
        
        for(int i=0; i<students.size(); i++)
        {
            stu.push(students[i]);
            san.push(sandwiches[i]);
        }
        int rot=0;
        
        while(stu.size()!=rot)
        {
            if(stu.front()==san.front())
            {
                stu.pop(); san.pop();
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
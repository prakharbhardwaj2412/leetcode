class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size(), n=goal.size();
        if(m!=n) return false;
        queue<char> q1, q2;
        for(char x:s) q1.push(x);
        for(char x:goal) q2.push(x);
        
        while(n)
        {
            char x=q2.front();
            q2.pop();
            q2.push(x);
            if(q1==q2) return true;
            n--;
        }
        return false;
     }
};
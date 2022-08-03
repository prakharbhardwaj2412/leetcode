class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        int res=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(') 
            {
                st.push(s[i]);
                count++;
            }
            else if(s[i]==')' && st.top()=='(') 
            {
                count--;
                st.pop();
            }
            res=max(res, count);
            
        }
        return res;
    }
};
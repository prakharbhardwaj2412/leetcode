class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        stack<int> st;
        int c=1;
        for(int i=n-1; i>=0; i--)
        {
            int t=digits[i]+c;
            st.push(t%10);
            c=t/10;
            
        }
        if(c>0) {st.push(c); n++;}
        digits.clear();
        for(int i=0; i<n; i++) 
        {
            int t=st.top();
            digits.push_back(t);
            st.pop();
        }
        return digits;
    }
};
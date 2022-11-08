class Solution {
public:
    void check(int i, string &s) {
        cout<<i<<" "<<s<<" "<<s.size()<<endl;
        if(i >= s.size()) return;
        if(abs(s[i] - s[i+1]) == 32) {
            s.erase(s.begin() + i + 1);
            s.erase(s.begin() + i);
            check(0, s);
        } else if(i<s.size()-1) 
        {
            cout<<"hello"<<endl;
            check(i+1, s);
        }
    }
    string makeGood(string s) {
        check(0, s);
        return s;
    }
};
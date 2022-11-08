class Solution {
public:
    void check(int i, string &s) {
        if(i >= s.size()) return;
        if(abs(s[i] - s[i+1]) == 32) {
            s.erase(s.begin() + i + 1);
            s.erase(s.begin() + i);
            check(0, s);
        } else if(i<s.size()-1) 
            check(i+1, s);
    }
    string makeGood(string s) {
        check(0, s);
        return s;
    }
};
class Solution {
public:
    string makeGood(string s) {
        // RECURSIVE
        for(int i=0; i<s.size(); i++) {
            if(abs(s[i] - s[i+1]) == 32) {
                s.erase(s.begin() + i + 1);
                s.erase(s.begin() + i);
                return makeGood(s);
            }
        }
        return s;
        // ITTERATIVE
        int i=0;
        while(s.size() > 1 && i < s.size()) {
            if(abs(s[i] - s[i+1]) == 32) {
                s.erase(s.begin() + i + 1);
                s.erase(s.begin() + i);
                i = 0;
            } else {
                i++;
            }
        }
        return s;
    }
};
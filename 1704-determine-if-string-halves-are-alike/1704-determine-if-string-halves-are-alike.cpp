class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int first = 0, second = 0;
        for(int i = 0; i < n; i++) {
            s[i]=tolower(s[i]);
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u') {
                if(i < n/2) first++;
                else second++;
            }
        }
        
        return first==second;
    }
};
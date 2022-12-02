class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> w1(26, 0), w2(26, 0);
        set<char> s1, s2;
        
        for(int i = 0; i < word1.size(); i++) {
            w1[word1[i] - 'a']++;
            w2[word2[i] - 'a']++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        } 
        
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        
        return w1==w2 && s1==s2;
    }
};
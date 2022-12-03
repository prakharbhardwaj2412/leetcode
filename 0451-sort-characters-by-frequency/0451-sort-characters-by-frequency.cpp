class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        
        for(char c : s) freq[c]++;
        
        for(auto it : freq) {
            bucket[it.second].append(it.second, it.first);
        }
        
        string ans = "";
        for(int i = s.size(); i>=0; i--) {
            if(bucket[i].size() > 0) ans+=bucket[i];
        }
        return ans;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int it : arr) freq[it]++;
        
        set<int> freqSet;
        
        for(auto [ket, value] : freq) {
            freqSet.insert(value);
        }
        
        return freq.size() == freqSet.size();
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int it : arr) mpp[it]++;
        
        set<int> st;
        
        for(auto it : mpp) {
            if(st.find(it.second) != st.end()) return false;
            else st.insert(it.second);
        }
        
        return true;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        
        for(char c : s) mpp[c]++;
        
        
        vector<pair<int, char>> arr;
        
        for(auto it : mpp) arr.push_back({it.second, it.first});
        sort(arr.begin(), arr.end());
        
        string ans = "";
        
        for(int i = arr.size()-1; i >= 0; i--) {
            for(int j = 0; j < arr[i].first; j++) ans += arr[i].second;
        }
        return ans;
    }
};
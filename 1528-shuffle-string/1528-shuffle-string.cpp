class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        char arr[n];
        for(int i=0; i<n; i++)
        {
            arr[indices[i]] = s[i];
            
        }
        for(int i=0; i<n; i++) s[i]=arr[i];
        return s;
    }
};
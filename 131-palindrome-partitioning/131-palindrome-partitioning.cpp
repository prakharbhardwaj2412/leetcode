class Solution {
public:
    bool isPalindrome(string s) {
        // cout<<s<<" ";
        int i=0, j=s.size()-1;
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        // cout<<s<<endl;
        return true;
    }
    
    void returnPartition(int ind, string s, vector<string> &part, vector<vector<string>> &ans) {
        cout<<ind<<endl;
        if(ind==s.size()) {
            ans.push_back(part);
            return;
        }
        string t="";
        for(int i=ind; i<s.size(); i++)
        {
            t+=s[i];
            cout<<"i="<<i<<" "<<t<<endl;
            if(isPalindrome(t)) 
            {
                part.push_back(t);
                returnPartition(i+1, s, part, ans);
                if(part.size()>0) part.pop_back();
            }
            else
            {
                // part.clear();
                // break;
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        string t="";
        returnPartition(0, s, part, ans);
        return ans;
    }
};
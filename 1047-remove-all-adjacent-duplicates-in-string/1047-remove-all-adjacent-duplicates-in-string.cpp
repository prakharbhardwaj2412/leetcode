class Solution {
public:
    string removeDuplicates(string s) {
        // int i=0, j=1;
        // while(s.size()>1 && j<s.size()) {
        //     if(s[i]==s[j]) {
        //         s.erase(s.begin()+j);
        //         s.erase(s.begin()+i);
        //         if(i!=0) {
        //             j=i;
        //             i=i-1;
        //         }
        //     } else {
        //         i++;
        //         j++;
        //     }
        // }
        // return s;
        
        // 
        string res;
        for(char &c : s) {
            if(res.size() && c==res.back()) res.pop_back();
            else res.push_back(c);
        }
        return res;
        
    }
};
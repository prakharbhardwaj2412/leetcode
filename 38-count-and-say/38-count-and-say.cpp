class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        int count=0;
        string temp="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==s[i+1]) count++;
            else 
            {
                temp+=to_string(count+1)+s[i];
                count=0;
            }
        }
        return temp;
        
    }
};
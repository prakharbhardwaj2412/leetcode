class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(char x:s)
        {
            if(x>='a' && x<='z') str+=x;
            else if(x>='A' && x<='Z') str+=x+32;
            else if(isalnum(x)==8) str+=x;
            cout<<isalnum(x)<<" "<<x<<endl;
        }
        // cout<<str;
        for(int i=0, j=str.size()-1; i<j; i++, j--)
            if(str[i]!=str[j]) return false;
        return true;
    }
};
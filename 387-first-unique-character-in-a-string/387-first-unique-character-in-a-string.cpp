// // METHOD 1
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int arr[26]={0};
        
//         for(char x:s)
//             arr[x-'a']++;
//         for(int i=0; i<s.size(); i++)
//             if(arr[s[i]-'a']==1) return i;
//         return -1;
//     }
// };

// METHOD 2 ===============================
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int arr[26];
//         for(int i=0; i<26; i++) arr[i]=-1;
//         for(int i=0; i<s.size(); i++)
//         {
//             if(arr[s[i]-'a'] == -1) arr[s[i]-'a']=i;
//             else arr[s[i]-'a']=-2;
//         }
        
//         int index=INT_MAX;
//         for(int x:arr)
//             if(x>=0) index=min(index, x);
//         if(index==INT_MAX) return -1;
//         return index;
//     }
// };

// METHOD 3
class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0; i < s.length(); i++)
       {

           if (s.find(s[i] ,s.find(s[i])+1) == string::npos)
           {
               return i;

               break;
           }
       }
       return -1;
    }
};
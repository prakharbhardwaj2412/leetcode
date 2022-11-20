class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
//         Intuition:
    //         Consider trust as a graph, all pairs are directed edge.
    //         The point with in-degree - out-degree = N - 1 become the judge.

//         Explanation:
    //         Count the degree, and check at the end.

//         Time Complexity:
    //         Time O(T + N), space O(N)
        vector<int> count(n + 1, 0); 
        
        for (auto& t : trust) {
            count[t[0]]--; count[t[1]]++;
        }
        
        for(int i = 1; i <= n; i++) if(count[i] == n - 1) return i;
        
        return -1;

    }
};
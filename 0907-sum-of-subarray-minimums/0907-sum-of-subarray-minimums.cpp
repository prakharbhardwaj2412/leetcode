class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        // int prevSmaller, nextSmaller, mid;
        int sumOfMinimums = 0;
        stack<int> st;
        
        for(int i = 0; i <= arr.size(); i++) {
            while(!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int leftBound = st.empty()  ? -1 : st.top();
                int rightBound = i;
                
                long count = (mid - leftBound) * (rightBound - mid) % MOD;
                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            st.push(i);
        }
        
        return (int)sumOfMinimums;
    }
};
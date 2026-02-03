class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0, n=nums.size();
        while (i < n-1 && nums[i] < nums[i+1]) {
            i++;
        }
        int p=i;
        while (i < n-1 && nums[i] > nums[i+1]) {
            i++;
        }
        int q=i;
        while (i < n-1 && nums[i] < nums[i+1]) {
            i++;
        }

        return (0<p && p<q && q<i && i==n-1);
    }
};
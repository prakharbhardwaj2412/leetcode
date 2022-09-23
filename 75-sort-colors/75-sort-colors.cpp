class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
        
        
    }
    void swap(int &a, int &b)
    {
        int temp=b;
        b=a;
        a=temp;
    }
};
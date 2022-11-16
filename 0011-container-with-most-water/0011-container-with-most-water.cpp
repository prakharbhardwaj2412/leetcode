class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low=0, high=n-1;
        int maxi=0;
        
        while(low<high) {
            int cap = (high-low)*min(height[low], height[high]);
            maxi = max(maxi, cap);
            if(height[low]<height[high]) low++;
            else high--;
        }
        return maxi;
    }
};
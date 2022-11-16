class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low=0, high=n-1;
        int maxWater=0;
        
        while(low<high) {
            int water = (high-low)*min(height[low], height[high]);
            maxWater = max(maxWater, water);
            if(height[low]<height[high]) low++;
            else high--;
        }
        return maxWater;
    }
};
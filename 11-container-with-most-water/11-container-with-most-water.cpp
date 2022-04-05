class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, cap=0;
       while(i<j)
       {
           if(cap < min(height[i], height[j])*(j-i)) 
               cap=min(height[i], height[j]) * (j-i);
           if(height[i] <= height[j]) i++;
           else if (height [i] > height[j]) j--;
       }
        return cap;
    }
};
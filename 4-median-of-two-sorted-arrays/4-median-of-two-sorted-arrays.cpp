class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(), i=0, j=0;
        vector<int> nums3(n1+n2);
        double median = 0;
        
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
        
        int index = (n1+n2)/2;
        
        if((n1+n2) % 2 == 0)
        {
            median = double (nums3[index-1]+nums3[index])/2;
        }
        else
        {
            median=nums3[index];
        }
        
    return median;    
    }
    
};
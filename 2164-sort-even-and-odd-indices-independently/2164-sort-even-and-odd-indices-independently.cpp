class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        int i = 0, j = 0, k = 0;
        
        while(i < arr1.size() && j < arr2.size()) {
            nums[k++] = arr1[i++];
            nums[k++] = arr2[j++];
        }
        while(i < arr1.size()) nums[k++] = arr1[i++];
        while(j < arr2.size()) nums[k++] = arr2[j++];

        return nums;
    }
};
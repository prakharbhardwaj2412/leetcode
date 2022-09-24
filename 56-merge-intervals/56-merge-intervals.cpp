class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp(2);
        temp[0]=arr[0][0];
        temp[1]=arr[0][1];
        int i;
        for(int i=0; i<arr.size(); i++)
        {
            // cout<<i<<" "<<"["<<temp[0]<<","<<temp[1]<<"]"<<"["<<arr[i][0]<<","<<arr[i][1]<<"]"<<endl;
            if(arr[i][0]<=temp[1])
            {
                temp[1]=temp[1]<=arr[i][1]?arr[i][1]:temp[1];
            }
            else
            {
                ans.push_back(temp);
                temp[0]=arr[i][0];
                temp[1]=arr[i][1];
            }
        }
        ans.push_back(temp);
        
        return ans;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end(), greater<int>());
                
        while(stones.size() > 1)
        {
            int first_max = stones[0];
            int sec_max = stones[1];
            stones.erase(stones.begin()+1);
            stones.erase(stones.begin());
            stones.push_back(first_max-sec_max);
            sort(stones.begin(), stones.end(), greater<int>());
        }
        
        return stones[0];
        
    }
};
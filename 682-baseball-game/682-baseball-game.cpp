class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        int n=ops.size();
        
        for(string ch:ops)
        {
            if(ch == "+")
            {
                score.push_back(score.back() + score[score.size()-2]);
            }
            else if(ch == "D")
            {
                score.push_back(2*score.back());
            }
            else if(ch == "C")
            {
                score.pop_back();
            }
            else 
            {
                score.push_back(stoi(ch));
            }
        }
        
        int sum=0;
        
        for(int x:score)
        {
            sum+= x;
        }
        
        return sum;
        
    }
};
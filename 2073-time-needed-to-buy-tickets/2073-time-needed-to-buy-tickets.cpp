class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int loop=tickets[k], time=0;
        
        for(int i=0; i<tickets.size(); i++)
        {
            if(i<=k)
            {
                if(tickets[i]>loop) time+=loop;
                else time+=tickets[i];
            }
            else
            {
                if(tickets[i]>=loop) time+=loop-1;
                else time+=tickets[i];
            }
        }
        return time;
        
    }
};
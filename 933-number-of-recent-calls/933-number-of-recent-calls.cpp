class RecentCounter {
public:
    queue<int> Q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // arr.push_back(t);
        // int count=0;
        // for(int x:arr)
        // {
        //     if(x>=t-3000 && x<=t) count++;
        // }
        // return count;
        Q.push(t);
        while(Q.front()<t-3000) Q.pop();
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
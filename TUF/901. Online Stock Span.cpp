class StockSpanner {
public:
    stack<pair<int,int>>store;
    int count;
    StockSpanner() {
        count = 1;
    }
    
    int next(int price) {
        while(!store.empty() && store.top().first <= price){
            store.pop();
        }
        int answer;
        
        if(!store.empty()){
            answer = (count - store.top().second) ;
        }else{
            answer = count;
        }
        store.push({price,count});
        count++;
        return answer;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
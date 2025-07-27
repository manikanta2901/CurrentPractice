class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int answer = INT_MIN;
        int rightMax = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            rightMax = max(rightMax,prices[i]);
            answer = max(answer,rightMax - prices[i]);
        }
        return answer;
    }
};
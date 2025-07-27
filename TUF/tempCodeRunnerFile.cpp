class Solution{
    public : 
        int getMinimumNumberOfCoins(vector<int>&denominations,int amount){
            int count = 0;
            sort(denominations.begin(),denominations.end(),greater<int>());
            int size = denominations.size();
            int i = 0;
            while(amount > 0 && i < size){
                count += (amount / denominations[i]);
                amount = amount % denominations[i];
                i++;
            }
            return (amount == 0 ? count : -1);
        }
};
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i = 0;
        int j = 0;
        int count = 0;
        int m = players.size();
        int n = trainers.size();
        for(int i = 0; i < m; i++){
            while(j < n && players[i] > trainers[j]){
                j++;
            }
            if(j < n && players[i] <= trainers[j]){
                count++;
                j++;
            }
        }
        return count;
    }
};
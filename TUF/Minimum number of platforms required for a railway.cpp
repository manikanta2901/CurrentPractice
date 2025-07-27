#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int platformsRequired(vector<int>&arrival,vector<int>&departure){
            int size = arrival.size();
            vector<pair<int,char>>trains;
            for(int i = 0; i < size; i++){
                trains.push_back({arrival[i],'A'});
                trains.push_back({departure[i],'D'});
            }
            sort(trains.begin(),trains.end());

            int count = 0;
            int platformsRequired = 0;
            size = trains.size();
            for(int i = 0; i < size; i++){
                if(trains[i].second == 'A'){
                    count++;
                    platformsRequired = max(platformsRequired,count);
                }else{
                    count--;
                }
            }
            return platformsRequired;
        }
};

int main(){

    return 0;
}
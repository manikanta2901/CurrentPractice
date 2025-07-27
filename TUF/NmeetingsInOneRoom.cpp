#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int startTime;
    int endTime;
    int index;
};



class Solution{
    private:
        bool static cmp(meeting &one,meeting &two){
           return one.endTime < two.endTime;
        }
    public:
        int NmeetingsInOneRoom(vector<int>&start,vector<int>&end){
            int size = start.size();
            vector<meeting>meetings(size);
            for(int i = 0; i < size; i++){
                meetings[i].startTime = start[i];
                meetings[i].endTime = end[i];
                meetings[i].index = i;
            }

            sort(meetings.begin(),meetings.end(),cmp);

            int freeTime = meetings[0].endTime;
            int count = 1;

            for(int i = 1; i < size; i++){
                if(meetings[i].startTime >= freeTime){
                    freeTime = meetings[i].endTime;
                    count++;
                }
            }
            return count;
        }
};

int main(){

    return 0;
}
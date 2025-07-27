#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

class Solution{
    private:
        bool static comp(const Job& one,const Job& two){
            return one.profit > two.profit;
        }
    public:
        int getMaxProfit(vector<Job>&jobs){
            int size = jobs.size();
            sort(jobs.begin(),jobs.end(),comp);
            int count = 0;
            int maxDeadline = 0,maxProfit = 0;
            for(int i = 0; i < size; i++){
                maxDeadline = max(maxDeadline,jobs[i].deadline);
            }

            vector<int>days(maxDeadline + 1, -1);
            for(int i = 0; i < size; i++){
                for(int j = jobs[i].deadline; j > 0; j--){
                    if(days[j] == -1){
                        count++;
                        days[j] = jobs[i].id;
                        maxProfit += jobs[i].profit;
                        break;
                    }
                }
            }
            return maxProfit;
        }
};

int main(){

    return 0;
}
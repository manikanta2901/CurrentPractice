#include<bits/stdc++.h>
using namespace std;

struct Item{
    int val;
    int weight;
};

class Solution{
    bool static cmp(const Item& one, const Item& two){
        return ((double)one.val / one.weight) > ((double)two.val / two.weight);
    }

    public:
        double getMaximumVal(vector<Item>items,int weight){
            int size = items.size();
            double maxValue = 0;
            sort(items.begin(),items.end(),cmp);
            for(int i = 0; i < size; i++){
                if(items[i].weight <= weight){
                    maxValue += items[i].val;
                    weight -= items[i].weight;
                }else{
                    maxValue += (((double) items[i].val )/ items[i].weight) * weight;
                    break;
                }
            }
            return maxValue;
        }
};

int main(){
    return 0;
}
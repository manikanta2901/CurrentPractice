#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>fre;
        int size = arr.size();
        for(int i = 0; i < size; i++){
            fre[arr[i]]++;
        }
        int answer = -1;
        for(auto &[key,val] : fre){
            if(key == val){
                answer = max(answer,key);
            }
        }
        return answer;
    }
};

int main(){
    Solution obj;
    int size; 
    cin >> size; 
    vector<int>nums(size);
    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    cout << obj.findLucky(nums) << endl;
    return 0;
}
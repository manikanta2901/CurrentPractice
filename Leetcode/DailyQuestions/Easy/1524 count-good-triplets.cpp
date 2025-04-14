#include<bits/stdc++.h>
using namespace std;

// 1524. Count Good Triplets
// https://leetcode.com/problems/count-good-triplets/
// Brute Force
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size = arr.size();
        int answer = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                for(int k = j + 1; k < size; k++){
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }

    // Optimized
    // https://youtu.be/yTTtuxccFdU?si=XtruUy2xyiK_l-DO

    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size = arr.size();
        int answer = 0;
        vector<int> prefix_sum(1001,0);
        for(int j = 0; j < size; j++){
            for(int k = j + 1; k < size; k++){
                if(abs(arr[j] - arr[k]) <= b){
                    int left1 = arr[j] - a, left2 = arr[k] - c;
                    int right1 = arr[j] + a, right2 = arr[k] + c;
                    int left = max(0,max(left1,left2));
                    int right = min(1000,min(right1,right2));
    
                    if(left <= right){
                        if(left > 0){
                            answer += prefix_sum[right] - prefix_sum[left - 1];
                        }else{
                            answer += prefix_sum[right];
                        }
                    }
                }
            }
            // Incrementing the entire prefix array to know how many numbers are greater than arr[j]
            for(int k = arr[j]; k <= 1000; k++){
                prefix_sum[k]++;
            }
        }
        return answer;
    }
};



int main(){
    Solution s;
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int a,b,c;
    cin >> a >> b >> c;
    cout << s.countGoodTriplets(nums, a, b, c) << endl; 
}
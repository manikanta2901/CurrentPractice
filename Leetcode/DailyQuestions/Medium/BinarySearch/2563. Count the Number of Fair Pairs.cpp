#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countFairPairsBrute(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        long long count = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                long int sum = nums[i] + nums[j];
                if(lower <= sum && upper >= sum){
                    count++;
                }
            }
        }
        return count;
    }


    long long countFairPairsBinarySearch(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        long long count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < size; i++){
            // number of elements less than lower - nums[j] <= nums[i]
            int low = lower_bound(nums.begin() + i + 1,nums.end(),lower - nums[i])- nums.begin();
            // number of elements greater than upper - nums[j] >= nums[i]
            int high = upper_bound(nums.begin() + i + 1,nums.end(),upper - nums[i])- nums.begin();
            count += 1LL * (high - low);
        }
        return count;
    }

    // Two pointers
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        long long count = 0;
        sort(nums.begin(),nums.end());
        // [lower,upper] = [0,upper] -[0,lower];
        return lowerBound(nums,upper + 1) - lowerBound(nums,lower);
    }

    long long lowerBound(vector<int>&nums,int value){
        int low = 0;
        int high = nums.size() - 1;
        long long answer = 0;
        while(low < high){
            int sum = nums[low] + nums[high];
            // In range less than value
            if(sum < value){
                answer += (high - low);
                low++;
            }else{
                high--;
            }
        }
        return answer;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int>nums;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int lower, upper;
    cin >> lower >> upper;
    Solution obj;
    cout << obj.countFairPairs(nums, lower, upper);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        int getLengthOfLongestSubarrayWithSumK(vector<int>&nums,int k){
            int size = nums.size();
            unordered_map<int,int>prefixMap;
            int prefixSum = 0;
            int maxLength = 0;
            for(int i = 0; i < size; i++){
                prefixSum += nums[i];
                if(prefixSum == k){
                    maxLength = max(maxLength, i + 1);
                }

                int remainingSum = prefixSum - k;
                if(prefixMap.find(remainingSum) != prefixMap.end()){
                    maxLength = max(maxLength, i - prefixMap[remainingSum] + 1);
                }
                if(prefixMap.find(prefixSum) == prefixMap.end()){
                    prefixMap[prefixSum] = i;
                }
            }
            return maxLength;
        }

        //Sliding window or two pointers
        // int getLengthOfLongestSubarrayWithSumK(vector<int>&nums,int k){
        //     int size = nums.size();
        //     int right = 0;
        //     int left = 0;
        //     int currentSum = nums[0];
        //     int maxLength = 0;
        //     while(right < size){
        //         while(left <= right && currentSum > k){
        //             currentSum -= nums[left];
        //             left++;
        //         }
                
        //         if(currentSum == k){
        //             maxLength = max(maxLength,right - left + 1);
        //         }
        //         right++;
                
        //         if(right < size){
        //             currentSum += nums[right];
        //         }
        //     }
            
        //     return maxLength;
        // }

        //Sliding window or two pointers
        int getLengthOfLongestSubarrayWithSumK(vector<int>&nums,int k){
            int size = nums.size();
            int right = 0;
            int left = 0;
            int currentSum = 0;
            int maxLength = 0;
            while(right < size){
                currentSum += nums[right];
                if(currentSum == k){
                    maxLength = max(maxLength,right - left + 1);
                }

                while(left <= right && currentSum > k){
                    currentSum -= nums[left];
                    left++;
                }
                right++;
            }
            
            return maxLength;
        }
};

int main(){

    return 0;
}
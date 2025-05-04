#include<bits/stdc++.h>
using namespace std;

//  1 number one time remainingNumbers 2 times
int findUniqueNumber(vector<int>&nums){
    int size = nums.size();
    int unique = 0;
    for(int i = 0; i < size; i++){
        unique = unique ^ nums[i];
    }
    return unique;
}

// 2 numbers one time remaining numbers 2 times

// Find xor of all numbers we will get result as xor of two unqiue numbers
// Now find the last set bit position in the result. now take xor of all the numbers whose set bit matches
// now we will get one number.

void findTwoUniqueNumbers(vector<int>&nums){
    int uniqueZor = 0;
    int size = nums.size();
    for(int i = 0; i < size; i++){
        uniqueZor = uniqueZor ^ nums[i];
    }
    int one = uniqueZor;
    int setBit = 0;
    int pos = 0;
    while(setBit != 1){
        setBit = uniqueZor & 1; // gets last bit value
        pos++;
        uniqueZor = uniqueZor >> 1;
    }

    int xorSum = 0;
    for(int i = 0; i < size; i++){
        if((nums[i] & (1 << (pos - 1))) != 0){
            xorSum = xorSum ^ nums[i];
        }
    }
    ;
    cout << xorSum << " " << (one ^ xorSum);
}

bool getBit(int n, int pos){
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos){
    return (n | (1 << pos));
}

// All the numbers are repeated three times except one
// Idea is to check fre of each bit for all the numbers
// All will be in multiple of 3. If not that bit is set in our required number

int unique(vector<int>&arr, int n){
    int result = 0;
    for (int i = 0; i < 64; i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (getBit(arr[j], i)){
                sum++;
            }
        }
        if (sum % 3 != 0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main(){
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    // cout << findUniqueNumber(nums) << endl;
    findTwoUniqueNumbers(nums);
    return 0;
}
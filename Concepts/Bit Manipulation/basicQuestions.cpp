#include<bits/stdc++.h>
using namespace std;

// To handle n = 0 we use n && here
bool isPowerOf2(int n){
    return (n && !(n & (n - 1)));
}

int noOfOnes(int n){
    int count = 0;
    while(n > 0){
        n = (n & n - 1);
        count++;
    }
    return count;
}

void printSubset(vector<int>&nums,int n){
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            // j th bit in i is set or not
            if(i & (1 << j)){
                cout << nums[j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    // cout << isPowerOf2(n) << endl;
    cout << noOfOnes(n) << endl;
    vector<int>nums = {1,2,3};
    printSubset(nums,3);
    return 0;
}
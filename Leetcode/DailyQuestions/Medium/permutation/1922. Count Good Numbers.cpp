#include<bits/stdc++.h>
using namespace std;

// Problem : 1922. Count Good Numbers1922. Count Good Numbers
// Link : https://leetcode.com/problems/count-good-numbers/
// Logic : In even positions we can have 5 digits (0,2,4,6,8) and in odd positions we can have 4 digits (1,3,5,7)
// So if n is even then we can have n/2 even positions and n/2 odd positions
// So the answer will be 5^(n/2) * 4^(n/2)
// If n is odd then we can have (n/2) + 1 even positions and (n/2) odd positions
// So the answer will be 5^((n/2) + 1) * 4^(n/2)
// Approach : We can use modular exponentiation to calculate the answer in O(log n) time
// Complexity : O(log n) time and O(1) space


class Solution {
    int modularExponentiation(int base,long long int n,int p,int result){
        while(n){
            if(n % 2 == 1){
                result = ((long long)(result % p) * base) % p;
                n--; 
            }else{
                base = ((long long)(base %p) * base ) % p;
                n /= 2;
            }
        }
        return result;
    }
public:
    // TLE direct approach
    // int countGoodNumbers(long long n) {
    //     int answer = 1;
    //     int MOD = 1e9 + 7;
    //     bool alternative = true;
    //     while(n > 0){
    //         if(alternative){
    //             answer = (long(answer) % MOD * 5) % MOD;
    //             alternative = false;
    //         }else{
    //             answer = (long(answer) % MOD * 4) % MOD;
    //             alternative = true;
    //         }
    //         n--;
    //     }
    //     return answer;
    // }

    int countGoodNumbers(long long n) {
        int answer = 1;
        int MOD = 1e9 + 7, count = 0;
        bool alternative = true;
        if(n % 2 == 1){
            count++;
        }
        answer = modularExponentiation(5, (n / 2) + count ,MOD,answer);
        answer = modularExponentiation(4, (n / 2),MOD,answer);
        return answer;
    }
};

int main(){
    Solution s;
    long long int n;
    cin >> n;
    cout << s.countGoodNumbers(n) << endl;
    return 0;
}
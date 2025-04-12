#include<bits/stdc++.h>
using namespace std;

// 3272. Find the Count of Good Integers
// https://leetcode.com/problems/find-the-count-of-good-integers/

// Logic 

// Palindrome is nothing but left half = right half.
// So max length of left half is total length / 2 + 1
// So we can iterate from 10^(n-1) to 10^n - 1 and create the palindrome.
// Now check created palindrom eis divisible by k or not.
// if yes We are adding into set to remove duplicate counts of permuatations.
// Now we are counting the fre of each digit in the palindrome and calculating the permutations of the digits in the palindrome.
// Now may have 0 and repetitions of digits also so the formula is 
// nonZeros * (totalDigits - 1)! / (f[0]! * f[1]! * f[2]! ... f[9]!)
// This is nothing but fixing nonZeroNumbes at first place and then there will be n - 1 places to fill, divide by each number fre to get the 
// total number of required permuations

// Youtube link: https://youtu.be/4I1c9esy54s?si=v8LOKleulVHn2rbr
class Solution {
    public:
        long long countGoodIntegers(int m, int k) {
        unordered_set<string>palindromes;
        int n = (m + 1) / 2;
        int start = pow(10,n - 1);
        int end = pow(10,n);
        long long answer = 0;
        vector<long long> factorial(11,1);
        for(int i = 1; i < 11; i++){
            factorial[i] = i * factorial[i - 1];
        } 
        for(int i = start; i < end; i++){
            string left = to_string(i);
            string full = left;
            if(m % 2 == 1){
                left.erase(left.begin() + left.size() - 1);
            }
            reverse(left.begin(),left.end());
            full += left;

            long long num = stoll(full);
            if(num % k != 0){
                continue;
            }
            sort(full.begin(),full.end());
            palindromes.insert(full);
        }
        
        for(auto s : palindromes){
            int fre[10] = {0};
            for(int j = 0; j < s.size(); j++){
                fre[s[j] - '0']++;
            }
            int totalDigits = s.size();
            int zeros = fre[0];
            int nonZeros = totalDigits - zeros;
            long long permutations = nonZeros * factorial[totalDigits - 1];
            for(int i = 0; i < 10; i++){
                permutations /= factorial[fre[i]];
            }
            answer += permutations;
        }
        return answer;
    }
};

int main() {
    Solution sol;
    int m, k;
    cin >> m >> k;
    cout << sol.countGoodIntegers(m, k) << endl;
    return 0;
}
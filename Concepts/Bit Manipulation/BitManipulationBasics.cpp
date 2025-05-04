#include<bits/stdc++.h>
using namespace std;

// 1 << position 
// if position is 2
//  1 << 2 -> 0100

int getBit(int n,int position){
    return (n & (1 << position)) != 0;
}

int setBit(int n,int position){
    return (n | (1 << position));
}

int clearBit(int n, int position){
    return (n & (~(1 << position)));
}

int updateBit(int num, int pos, int value) {
    if (value == 0) {
        return clearBit(num, pos); 
    } else {
        return setBit(num, pos);    
    }
}

int main(){
    int n,position;
    cin >> n >> position;
    cout << "Get Bit at " << position << " is " <<  getBit(n,position) << endl;
    cout << "Set Bit at " << position << " is " <<  setBit(n, position) << endl;
    cout << "Cleared Bit at " << position << " value is " << clearBit(n,position) << endl;
}
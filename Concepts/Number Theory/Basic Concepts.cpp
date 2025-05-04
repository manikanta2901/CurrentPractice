#include<bits/stdc++.h>
using namespace std;


int EclidDivionToFindHcf(int a,int b){
    if(b == 0){
        return a;
    }
    return EclidDivionToFindHcf(b,a % b);
}

int binaryExponentiation(int base,int n,int MOD){
    int answer = 1;
    while(n > 0){
        if(n % 2 == 1){
            answer = ((answer) * base) % MOD;
            n--;
        }else{
            base = (base * base) % MOD;
            n = n / 2;
        }
    }
    return answer;
}

void factors(int n){
    vector<int>factors;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            factors.push_back(i);
            if(n / i != i){
                factors.push_back(n / i);
            }
        }
    }
    for(auto it : factors){
        cout << it << " ";
    }
}

int main(){
    int n;
    cin >> n;
    factors(n);
    return 0;
}
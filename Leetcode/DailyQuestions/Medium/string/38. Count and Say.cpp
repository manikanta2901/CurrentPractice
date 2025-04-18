#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string answer = "1";
        while(--n){
            int count = 1;
            string store = "";
            for(int i = 0; i < answer.size(); i++){
                if(i + 1 < answer.size() && answer[i] == answer[i + 1]){
                    count++;
                }else{
                    store += to_string(count);
                    store += answer[i];
                    count = 1;
                }
            }
            answer = store;
        }
        return answer;
    }
};
    

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.countAndSay(n) << endl;

    return 0;
}
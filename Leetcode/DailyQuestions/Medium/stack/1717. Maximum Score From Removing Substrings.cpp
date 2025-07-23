// Optimal
class Solution {
    string removeOccurrences(string s, string part) {
        int size = s.size();
        stack<char>store;
        int partSize = part.size();
        for(int i = 0; i < size; i++){
            if(part[1] == s[i] && !store.empty() && store.top() == part[0]){
               store.pop(); 
            }else{
                store.push(s[i]);
            }
        }
        string answer = "";
        while(!store.empty()){
            answer += (store.top());
            store.pop();
        }
        return answer;
    }
public:
    int maximumGain(string s, int x, int y) {
        string required = (x > y) ? "ab" : "ba"; 
        int answer = 0;
        int size = s.size();
        s = removeOccurrences(s,required);
        int newSize = s.size();
        answer += ((size - newSize) / 2) * max(x,y);
        s = removeOccurrences(s,required);
        answer += ((newSize - s.size()) / 2)* min(y,x);
        return answer;
    }
};


// Brute Force
class Solution {
    bool isValid(string part,stack<char>&store){
        stack<char>temp = store;
        int partSize = part.size();
        for(int i = partSize -1; i >= 0; i--){
            if(temp.empty() || temp.top() != part[i]){
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int size = s.size();
        stack<char>store;
        int partSize = part.size();
        for(int i = 0; i < size; i++){
            store.push(s[i]);
            if(isValid(part,store)){
                for(int j = 0; j < partSize; j++){
                    if(!store.empty()){
                      store.pop();   
                    }
                }
            }
        }
        string answer = "";
        while(!store.empty()){
            answer += (store.top());
            store.pop();
        }
        // reverse(answer.begin(),answer.end());
        return answer;
    }
public:
    int maximumGain(string s, int x, int y) {
        stack<string>store;
        string required = (x > y) ? "ab" : "ba"; 
        int answer = 0;
        int size = s.size();
        s = removeOccurrences(s,required);
        int newSize = s.size();
        answer += ((size - newSize) / 2) * max(x,y);
        // cout << x << " " << answer << endl;
        s = removeOccurrences(s,required);
        answer += ((newSize - s.size()) / 2)* min(y,x);
        // cout << y << " " << answer << endl;
        return answer;
    }
};
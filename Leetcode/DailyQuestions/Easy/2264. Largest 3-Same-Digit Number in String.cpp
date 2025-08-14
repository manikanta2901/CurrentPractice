class Solution {
public:
    string largestGoodInteger(string num) {
        int size = num.size();
        int count = 0;
        int element = 0;
        int answer = -1;
        for(int i = 0; i < size; i++){
            int digit = (num[i] - '0');
            if(element == digit){
                count++;
            }else{
                element = digit;
                count = 1;
            }
    
            if(count == 3){
                answer = max(answer,element);
                count = 0;   
            }
        }
        if(answer == -1){
            return "";
        }
        char answerChar = '0' + answer;
        return string(3,answerChar);
    }
};
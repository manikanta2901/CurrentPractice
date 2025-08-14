class Solution {
public:
    string countAndSay(int n) {
        int times = n;
        int count = 1;
        string answer = "1";
        while(--times){
            int size = answer.size();
            string temp = "";
            for(int i = 0; i < size; i++){
                if(i + 1 < size && answer[i] == answer[i + 1]){
                    count++;
                }else{
                    temp += to_string(count);
                    temp += answer[i];
                    count = 1;
                }
            }
            answer = temp;
        }
       return answer;
    }
};

class Solution {
public:

    bool isValidPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void getAnswer(string s,vector<string>&partitionAnswer,vector<vector<string>>&answer){
        if(s.size() == 0){
            answer.push_back(partitionAnswer);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string firstPart = s.substr(0,i + 1);
            if(isValidPalindrome(firstPart)){
                partitionAnswer.push_back(firstPart);
                string secondPart = s.substr(i + 1);
                getAnswer(secondPart,partitionAnswer,answer);
                partitionAnswer.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string>partitionAnswer;
        getAnswer(s,partitionAnswer,answer);
        return answer;
    }
};
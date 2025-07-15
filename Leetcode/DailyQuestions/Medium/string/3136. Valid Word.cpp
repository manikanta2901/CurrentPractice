class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u';
    }
    bool isValid(string word) {
        int size = word.size();
        if(size < 3){
            return false;
        }
        bool vowel = false,cons = false;
        for(int i = 0; i < size; i++){
            if(!isalnum(word[i])){
                return false;
            }
            if(isdigit(word[i])){
                continue;
            }
            if(isVowel(word[i])){
                vowel = true;
            }else{
                cons = true;
            }
        }
        return vowel & cons;
    }
};
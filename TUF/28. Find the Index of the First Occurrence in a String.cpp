class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() == 0){
            return 0;
        }
        
        if(haystack.size() > 0 && needle.size() == 0){
            return 0;
        }
        if(haystack == needle){
            return 0;
        }
        
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        while(i < n){
            if(haystack[i] == needle[0]){
                if(i + m <= n && needle == haystack.substr(i,m)){
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
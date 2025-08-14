class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s == t;
        int m = s.size();
        int n = t.size();
        if(m != n){
            return false;
        }
        unordered_map<int,int>fre;
        for(int i = 0; i < m; i++){
            fre[s[i]]++;
            fre[t[i]]--;
        }
        for(auto& [ch,val] : fre){
            if(val > 0){
                return false;
            }
        }
        return true;
    }
};
struct Node{
    Node* links[26];
    int countPrefix = 0;

    bool isPresent(char ch){
        return links[ch - 'a'] != NULL;
    }

    void insert(Node* newNode,char ch){
        links[ch - 'a'] = newNode;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void decreasePrefixCount(){
        countPrefix--;
    }

    void increasePrefixCount(){
        countPrefix++;
    }

    int getCountPrefix(){
        return countPrefix;
    }
};

class Trie{
    private:
        Node* root;
    public:

        Trie(){
            root = new Node();
        }

        void insert(string s){
            int size = s.size();
            Node* rootCopy = root;
            for(int i = 0; i < size; i++){
                if(!rootCopy->isPresent(s[i])){
                    rootCopy->insert(new Node(),s[i]);
                }
                rootCopy = rootCopy->get(s[i]);
                rootCopy->increasePrefixCount();
            }
        }

        string search(string s,int count){
            int size = s.size();
            Node* rootCopy = root;
            string prefix = "";
            for(int i = 0; i < size; i++){
                rootCopy = rootCopy->get(s[i]);
                if(count == rootCopy->getCountPrefix()){
                    prefix += s[i];
                }else{
                    return prefix;
                }
            }
            return prefix;
        }
};

class Solution {
private:
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        Trie* trie = new Trie();
        for(int i = 0; i < size; i++){
            trie->insert(strs[i]);
        }
        return trie->search(strs[0],size);
    }
};
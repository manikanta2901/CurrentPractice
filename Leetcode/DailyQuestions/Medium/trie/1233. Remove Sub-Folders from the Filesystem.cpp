struct Node{
    map<string,Node*> links;
    bool endsWith = false;
    bool contains(string s){
        return links[s] != NULL;
    }
    void put(Node* newNode, string s){
        links[s] = newNode;
    }
    Node* get(string s){
        return links[s];
    }
    void setEnd(){
        endsWith = true;
    }
    bool getEnd(){
        return endsWith;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    bool insert(string s){
        Node* rootCopy = root;
        int size = s.size();
        for(int i = 1; i < size; i++){
            string temp = "";
            while(i < s.size() && s[i] != '/'){
                temp += s[i];
                i++;
            }
            if(!rootCopy->contains(temp)){
                rootCopy->put(new Node(),temp);
            }
            rootCopy = rootCopy->get(temp);
            if(rootCopy->getEnd()){
                return false;
            }
        }
        rootCopy->setEnd();
        return rootCopy->getEnd();
    }
};

class Solution {
public:
    vector<string>answer;
    bool static const comp(string &s1,string &s2){
        return s1.size()<s2.size();

    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),comp);
        int size = folder.size();
        Trie* trie = new Trie();
        for(int i = 0; i < size; i++){
            if(trie->insert(folder[i])){
                answer.push_back(folder[i]);
            }
        }
        return answer;
    }
};

// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         sort(folder.begin(), folder.end());

//         vector<string> result;
//         result.push_back(folder[0]);


//         for (int i = 1; i < folder.size(); i++) {
//             string lastFolder = result.back();
//             lastFolder += '/';

//             if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
//                 result.push_back(folder[i]);
//             }
//         }

//         return result;
//     }
// };

struct Node{
    map<string,Node*> links;
    bool endsWith = false;
    bool contains(string s){
        return links[s] != NULL;
    }
    void put(Node* newNode, string s){
        links[s] = newNode;
    }
    Node* get(string s){
        return links[s];
    }
    void setEnd(){
        endsWith = true;
    }
    bool getEnd(){
        return endsWith;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(vector<string> words){
        Node* rootCopy = root;
        int size = words.size();
        for(int i = 0; i < size; i++){
            string temp = words[i];
            if(!rootCopy->contains(temp)){
                rootCopy->put(new Node(),temp);
            }
            rootCopy = rootCopy->get(temp);
            if(rootCopy->getEnd()){
                return;
            }
        }
        rootCopy->setEnd();
    }

    void dfs(Node* current,vector<string>&answer,string path){
        if(current->getEnd()){
            answer.push_back(path);
            return;
        }

        for(auto &[childkey,childNode]: current->links){
            dfs(childNode,answer,path + "/" + childkey);
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int size = folder.size();
        Trie* trie = new Trie();
        for(int i = 0; i < size; i++){
            vector<string> words;
            stringstream ss(folder[i]);
            string part;
            while(getline(ss,part,'/')){
                if(!part.empty()){
                    words.push_back(part);
                }
            }
           trie->insert(words);
        }
        vector<string>answer;
        trie->dfs(trie->root,answer,"");
        return answer;
    }
};

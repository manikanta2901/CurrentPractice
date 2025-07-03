#include<bits/stdc++.h>
using namespace std;

struct Node{
    bool flag = false;
    Node* links[26];

    bool isPresent(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(Node* newNode,char ch){
        links[ch - 'a'] = newNode;
    }

    Node* get(char ch){
        return links[ch -'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isPresent(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int size = word.size();
        Node* rootCopy = root;
        for(int i = 0; i < size; i++){
            if(!rootCopy->isPresent(word[i])){
                rootCopy->put(new Node(),word[i]);
            }
            rootCopy = rootCopy->get(word[i]);
        }
        rootCopy->setEnd();
    }
    
    bool search(string word) {
        int size = word.size();
        Node* rootCopy = root;
        for(int i = 0; i < size; i++){
            if(!rootCopy->isPresent(word[i])){
                return false;
            }
            rootCopy = rootCopy->get(word[i]);
        }
        return rootCopy->isPresent();
    }
    
    bool startsWith(string prefix) {
        int size = prefix.size();
        Node* rootCopy = root;
        for(int i = 0; i < size; i++){
            if(!rootCopy->isPresent(prefix[i])){
                return false;
            }
            rootCopy = rootCopy->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){

}
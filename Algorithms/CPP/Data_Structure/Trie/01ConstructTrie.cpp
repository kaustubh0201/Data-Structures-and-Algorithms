#include<iostream>

using namespace std;

struct TrieNode{
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(int data){
        this->data = data;

        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie{

    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){

        // base case
        if(word.length() == 0){
            root->isTerminal = true;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }
};

int main(void){

    

    return 0;
}
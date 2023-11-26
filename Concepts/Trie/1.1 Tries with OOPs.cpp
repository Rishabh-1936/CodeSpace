#include <bits/stdc++.h>

#define SIZE 26
using namespace std;

class Tries{
    private:

    struct TrieNode {
        // The Trie Node Structure
        // Each node has N children, starting from the root
        // and a flag to check if it's a leaf node
        char data; // Storing for printing purposes only
        TrieNode* children[SIZE];
        bool isTerminal;
        bool isleaf;
        // map<char, Node> children;
    };

    TrieNode* root;
    int numOfWords;

    TrieNode* getTrieNode(char data){
        TrieNode* node = new TrieNode;
        node->data = data;
        node->isleaf = false;
        node->isTerminal = false;
        for(int i=0; i < SIZE; ++i){
            node->children[i] = NULL;
        }
        
        return node;
    }

    void insertWord(TrieNode* Parent, string word){
        int idx = 0;
        TrieNode* tempRoot = Parent;

        for(int i = 0; i<word.length(); ++i){
            idx = word[i] - 'a';
            if(tempRoot->children[idx] == NULL){
                tempRoot->children[idx] = getTrieNode(word[i]);
            }
            else{
                if(tempRoot->children[idx]->isTerminal){
                    tempRoot->children[idx]->isTerminal = false;
                }
            }
            tempRoot = tempRoot->children[idx];
        }
        tempRoot->isleaf = true;
        this->numOfWords++;
        
        // return tempRoot;
    }

    bool searchWord(TrieNode* Parent, string word){
        int idx = 0;
        TrieNode* tempRoot = Parent;

        for(int i = 0; i<word.length(); ++i){
            idx = word[i] - 'a';
            if(tempRoot->children[idx] == NULL){
                return false;
            }
            tempRoot = tempRoot->children[idx];
        }
        if(tempRoot->isleaf) 
            return true;

        return false;
    }
    
    void free_trienode(TrieNode* Parent){
        for(int i = 0; i < SIZE; ++i){
            if(Parent->children[i] != NULL){
                free_trienode(Parent->children[i]);
            }
        }
        delete (Parent);
    }
    
    bool deleteWord(TrieNode* Parent, string word){
        
        TrieNode* lastTerminal = NULL;
        TrieNode* tempRoot = Parent;
        int wLen = word.length();
        int pos = 0, idx;
        
        for(int i=0;i<wLen;++i){
            idx = word[i] - 'a';
            
            if(tempRoot->children[idx] == NULL){
                return false;
            }
            else if(tempRoot->children[idx]->isleaf && i < wLen - 1){
                lastTerminal = tempRoot->children[idx];
                pos = word[i+1]-'a';
            }
            
            tempRoot = tempRoot->children[idx];
        }
        
        lastTerminal = lastTerminal->children[pos];
        free_trienode(lastTerminal);
        
        return true;
        
    }

    public:
    Tries(){
        this->root = getTrieNode('\0');
        this->numOfWords = 0;
    }

    void insertWord(string word){
        this->insertWord(root, word);
    }

    bool searchWord(string word){
        return this->searchWord(root, word);
    }
    bool deleteWord(string word){
        return this->deleteWord(root, word);
    }
};

int main(){

    Tries *tries = new Tries();
    tries->insertWord("appy");
    tries->insertWord("apply");
    tries->insertWord("boards");
    tries->insertWord("board");
    
    cout<<"Before Delete"<<endl;
    cout<<tries->searchWord("apple") << endl;
    cout<<tries->searchWord("apply") << endl;
    cout<<tries->searchWord("board") << endl;
    cout<<tries->searchWord("boards") << endl;
    cout<<tries->searchWord("boardsxxc") << endl;
    
    tries->deleteWord("boards");
    
    cout<<"After Delete"<<endl;
    
    cout<<tries->searchWord("apple") << endl;
    cout<<tries->searchWord("apply") << endl;
    cout<<tries->searchWord("board") << endl;
    cout<<tries->searchWord("boards") << endl;
    return 0;
}
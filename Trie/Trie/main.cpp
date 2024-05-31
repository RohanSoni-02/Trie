//
//  main.cpp
//  Trie
//
//  Created by Rohan Soni on 30/5/2024.
//

#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
class Trie;

class Node{
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
public:
    Node(char data){
        data = data;
        isTerminal = false;
    }
    friend class Trie;
};

class Trie{
    Node* root;
    
public:
    Trie(){
        root = new Node('\0');
    }
    
    //prefix trie
    void insert(string word){
        Node* temp = root;
        for (char ch: word) {
            if(temp->m.count(ch)==0){
                Node* newNode = new Node(ch);
                temp->m[ch] = newNode;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    //suffix trie
    void insertSuff(string word){
        Node* temp = root;
        for (char ch: word) {
            if(temp->m.count(ch)==0){
                Node* newNode = new Node(ch);
                temp->m[ch] = newNode;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    void insertS(string word){
        for(int i=0; word[i] != '\0'; i++){
            insertSuff(word.substr(i));
        }
    }
    
    bool search(string word){
        Node* temp = root;
        for(char ch: word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main(int argc, const char * argv[]) {
    string words = "apple";
    string suffix[] = {"pple", "ple", "pel"};
    Trie t;
    t.insertS(words);
    
    for(auto sf: suffix){
        cout<<sf << " : " << (t.search(sf)?"True":"False")<<endl;
    }
    
}

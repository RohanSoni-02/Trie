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
    string words[] = {"apple", "ape", "hello", "hey","hell"};
    Trie t;
    for(auto word: words){
        t.insert(word);
    }
    string key;
    cin>>key;
    cout<<key << " : " << (t.search(key)?"True":"False")<<endl;
}

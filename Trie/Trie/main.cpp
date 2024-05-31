//
//  main.cpp
//  Trie
//
//  Created by Rohan Soni on 30/5/2024.
//

#include <iostream>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    Node(char data){
        data = 'd';
        isTerminal = false;
    }
};

class Trie{
    Node* root;
    
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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

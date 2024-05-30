//
//  main.cpp
//  Trie
//
//  Created by Rohan Soni on 30/5/2024.
//

#include <iostream>
using namespace std;

class Node{
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
public:
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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

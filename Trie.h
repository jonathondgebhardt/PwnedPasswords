#ifndef TRIE_H
#define TRIE_H

#define EMPTYNODE 'a'

#include <string>
#include <iostream>

class Trie
{
    private:

        class Node
        {
            public:
                Node* child;
                Node* sibling;
                char value;

                Node(char value) : value(value)
                {
                    child = nullptr;
                    sibling = nullptr;
                }

                Node()
                {
                    child = nullptr;
                    sibling = nullptr;
                    value = EMPTYNODE;
                }

                Node* insert(std::string word)
                {
                    std::cout << "\t" << word[0] << std::endl;


                    return nullptr;
                }
        };

        Node root;
        

    public:
        Trie();
        ~Trie();
        bool insert(std::string word);
        int count();
        int getSize();
        bool find(std::string prefix);
        int completeCount(std::string prefix);

};

#endif
#ifndef TRIE_H
#define TRIE_H

#define EMPTYNODE 'a'

#include <string>

class Trie
{
    private:

        class Node
        {
            public:
                Node* child;
                Node* sibling;
                char value;
        };

        Node root;
        Node* insert(Node t, std::string word);

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
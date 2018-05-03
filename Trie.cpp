#include "Trie.h"
#include <string>
#include <iostream>

#define EMPTYNODE 'a'

Trie::Trie()
{
    root = Node();
    root.child = nullptr;
    root.sibling = nullptr;
    root.value = EMPTYNODE;
}

Trie::~Trie()
{
    // std::cout << root->value << std::endl;
    // Should iterate list destroying nodes
}

bool Trie::insert(std::string word)
{
    if (word.length() < 1)
    {
        return false;
    }

    char currentLetter = (char) word[0];

    std::cout << "Inserting " << currentLetter << std::endl;
    
    // If trie is empty, we can insert first character
    if (root.value == EMPTYNODE)
    {
        // Since root did not exist before, it's empty and we can insert
        // value here
        
        root.value = currentLetter;
        return insert(*root.child, word.substr(1));
    }

    // If character exists, traverse and check next
    Node temp = root;
    while (!temp.sibling)
    {
        if (temp.value == (currentLetter))
        {
            std::cout << "\tFound " << currentLetter << std::endl;
            temp.child = insert(*temp.child, word.substr(1));
        }

        temp = *temp.sibling;
    }

    // If end of word is reached and that character already exists, 
    // word is already in trie, can return false

    // Else, new word -> add each character at appropriate layer

    return false;
}

Node* Trie::insert(Node t, std::string word)
{
    // std::cout << "\t" <<  << std::endl;


    return nullptr;
}

int Trie::count()
{
    return -1;
}

int Trie::getSize()
{
    return -1;
}

bool Trie::find(std::string prefix)
{
    return false;
}

int Trie::completeCount(std::string prefix)
{
    return -1;
}

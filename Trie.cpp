#include "Trie.h"
#include <string>
#include <iostream>

#define EMPTYNODE 'a'

Trie::Trie()
{
    root = Node(EMPTYNODE);
    root.child = nullptr;
    root.sibling = nullptr;
    //root.value = EMPTYNODE;
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
        root.child = root.insert(word.substr(1));
        return true;
    }

    // Check if value is already in list, traverse if found
    Node temp = root;
    while (temp.sibling)
    {
        std::cout << "Iterating list..." << std::endl;

        if (temp.value == currentLetter)
        {
            std::cout << "Found " << currentLetter << std::endl;

            if(word.length() == 0) 
            {
                return false;
            }


            if (!temp.child)
            {
                temp.child = new Node(currentLetter);
            }
            
            temp.child = temp.child->insert(word.substr(1));
            return true;
        }

        temp = *temp.sibling;
    }

    std::cout << "Did not find " << currentLetter << ", inserting new node" << std::endl;
    // Value is not in list, need to add
    temp.sibling = new Node(currentLetter);
    temp.sibling->child = new Node();
    temp.sibling->child = temp.sibling->child->insert(word.substr(1));

    return true;
}

// Node Node::insert(Node t, std::string word)
// {
//     // std::cout << "\t" <<  << std::endl;


//     return nullptr;
// }

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

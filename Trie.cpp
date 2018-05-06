#include "Trie.h"
#include <string>
#include <iostream>

#define EMPTYNODE 'a'
#define HASHLENGTH 4

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

/*
    Insert a new word into the trie. Duplicate words are not allowed. This function
    returns true if the word is successfully inserted into the trie, and false if the
    word could not be inserted.
*/
bool Trie::insert(std::string word)
{
    // Base case: sha1sum is a 40 char string
    if (word.length() != HASHLENGTH)
    {
        return false;
    }

    char currentLetter = (char) word[0];
    std::cout << "Inserting " << word[0] << std::endl;
    
    // If trie is empty, we can insert first character
    if (root.value == EMPTYNODE)
    {
        // Since root did not exist before, it's empty and we can insert
        // value here
        root.value = currentLetter;
        root.child = root.child->insert(word.substr(1));
        
        return true;
    }

    // Check if value is already in list, traverse if found
    Node temp = root;
    while (temp.sibling)
    {
        if (temp.value == currentLetter)
        {
            if (!temp.child)
            {
                temp.child = new Node(currentLetter);
            }
            
            temp.child = temp.child->insert(word.substr(1));
            return true;
        }

        temp = *temp.sibling;
    }

    // Value is not in list, need to add
    temp.sibling = new Node(currentLetter);
    temp.sibling->child = new Node();
    temp.sibling->child = temp.sibling->child->insert(word.substr(1));

    return true;
}

/*
    Return the number of words in the trie
*/
int Trie::count()
{
    return -1;
}

/*
    Return the total number of nodes in the trie
*/
int Trie::getSize()
{
    return -1;
}

/*
    If the given word is in the trie, return true, otherwise return false
*/
bool Trie::find(std::string prefix)
{
    return false;
}

/*
    Print out contents of trie using depth first traversal
*/
void Trie::display()
{
    // Print root, this is the first node
    std::cout << "---Trie contents---\n" << root.value << std::endl;

    Node* temp = root.sibling;
    while (temp) 
    {
        std::cout << temp->value << std::endl;
        temp = temp->sibling;
    }

}
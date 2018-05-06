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
                    if (word.length() < 1)
                    {
                        return this;
                    }

                    bool found = false;
                    char currentLetter = (char) word[0];

                    std::cout << "\tIn " << value << " insert" << std::endl;
                    
                    // Check if value is already in list, traverse if found
                    Node* temp = this;
                    while (temp->sibling)
                    {
                        if (temp->value == currentLetter)
                        {
                            if (temp->child)
                            {
                                temp->child = new Node(currentLetter);
                            }
                            
                            temp->child = temp->child->insert(word.substr(1));
                            found = true;
                            break;
                        }

                        temp = temp->sibling;
                    }

                    // Value is not in list, need to add
                    if (!found)
                    {
                        std::cout << "In not found statement" << std::endl;
                        temp->sibling = new Node(currentLetter);
                        temp->sibling->child = new Node();
                        temp->sibling->child = temp->sibling->child->insert(word.substr(1));
                    }
                    
                }

                // Checks breadth for target node
                Node* nodeExists(char target)
                {
                    if (!this)
                    {
                        return nullptr;
                    }

                    std::cout << "\t\t" << value << " ?= " << target << std::endl;

                    if (value == target)
                    {
                        return this;
                    }

                    return sibling->nodeExists(target);
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
        void display();
        // friend ostream& operator<<(ostream& os, const MagicBag& mb);

};

#endif
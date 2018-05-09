#ifndef TRIE_H
#define TRIE_H

#define EMPTYNODE '!'

#include "stdafx.h"
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

		void insert(std::string word)
		{
			// Base case: If there's no more letters to add
			if (word.length() < 1)
			{
				return;
			}

			char currentLetter = (char)word[0];

			// If the node we're on is empty, we can insert. Initialize
			// value and insert substring.
			if (this->value == EMPTYNODE)
			{
				this->value = currentLetter;

				if (word.substr(1).length() >= 1)
				{
					this->child = new Node();
					this->child->insert(word.substr(1));
				}
			}

			// Otherwise, we need to find an appropriate node
			else
			{
				Node* temp = this;
				while (temp)
				{
					// If the node has the value we are looking for, we can stop
					if (temp->value == currentLetter)
					{
						break;
					}

					// Iterate if there are more siblings to look at
					if (temp->sibling)
					{
						temp = temp->sibling;
					}

					// If there are no more siblings, and we haven't found the value
					// we're lookng for, we need a new sibling. Create one and insert
					// on that.
					else
					{
						temp->sibling = new Node();
						temp->sibling->insert(word);
						return;
					}
				}

				// We found the node we're looking for. If it doesn't have a child,
				// create one and continue inserting.
				if (word.substr(1).length() >= 1)
				{
					if (!temp->child)
					{
						temp->child = new Node();
					}

					temp->child->insert(word.substr(1));
				}	
			}
		}

		// Checks breadth for target node
		Node* nodeExists(char target)
		{
			// Base case: if called on empty node, nothing is in the layer yet.
			// Return a new node.
			if (this->value = EMPTYNODE)
			{
				return new Node(target);
			}

			// Found node we were looking for, return this.
			if (value == target)
			{
				return this;
			}

			// This isn't the node we're looking for and other nodes exist.
			// Keep looking.
			return sibling->nodeExists(target);
		}

		void display()
		{
			// Print root, this is the first node
			std::cout << this->value << std::endl;

			Node* temp = this;
			while (temp)
			{
				std::cout << temp->value << std::endl;
				temp = temp->sibling;
			}
		}

		int getWordCount()
		{
			int count = 0;
			// Base case: current node has no children. Since we're at a leaf,
			// we can stop looking. 
			if (!this->child)
			{
				Node* temp = this;
				while (temp)
				{
					count += 1;
					temp = temp->sibling;
				}
			}

			else
			{
				// Iterate for every sibling to current node
				Node* temp = this;
				while (temp)
				{
					count += temp->child->getWordCount();
					temp = temp->sibling;
				}
			}

			return count;
		}

		int getSize()
		{
			// Base case: current node is past a leaf, do not add
			// to total count.
			if (!this)
			{
				return 0;
			}

			// Otherwise, we can still have nodes to iterate over
			int count = 0;
			Node* temp = this;

			// Iterate for every sibling to current node
			while (temp)
			{
				count += 1 + temp->child->getSize();
				temp = temp->sibling;
			}

			return count;
		}

		bool find(std::string word)
		{
			// Base case: no more letters to check for. Since all sha1sum's
			// are the same length, if we've run out of letters, the word isn't
			// in the trie.
			if (word.length() < 1)
			{
				return false;
			}

			// Otherwise, we have at least one more letter. 
			char currentLetter = (char)word[0];

			// If there's only one more letter, return true if the current node's
			// value is the target
			if (word.length() == 1 && this->value == currentLetter)
			{
				return true;
			}

			// If neither of the above are true, we must look at children or
			// children of siblings
			Node* temp = this;
			while (temp)
			{
				// If the bottom of the stack frames return true, keep passing 
				// up the stack frames
				if (temp->child->find(word.substr(1)))
				{
					return true;
				}

				temp = temp->sibling;
			}

			return false;
		}
	};

	Node root;


public:
	Trie();
	~Trie();
	void insert(std::string word);
	int getWordCount();
	int getSize();
	bool find(std::string word);
	void display();
	// friend ostream& operator<<(ostream& os, const MagicBag& mb);

};

#endif
#include "stdafx.h"
#include "Trie.h"
#include <string>
#include <iostream>

#define EMPTYNODE '!'
#define HASHLENGTH 4

Trie::Trie()
{
	root = Node();
	/*rootchild = nullptr;
	root.sibling = nullptr;*/
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

	char currentLetter = (char)word[0];

	// If trie is empty, we don't need to look for an appropriate
	// node since there are none.
	if (root.value == EMPTYNODE)
	{
		root = Node(currentLetter);
		root.insert(word);
		return true;
	}

	// Otherwise, we look for an appropriate node to insert on
	else
	{
		Node* temp = &root;
		while (temp)
		{
			// If the current node has the value we're searching for,
			// we can stop.
			if (temp->value == currentLetter)
			{
				break;
			}

			// If the current node has a sibling, keep iterating.
			if (temp->sibling)
			{
				temp = temp->sibling;
			}

			// If there's no more siblings and we haven't found the
			// node we're looking for, we need to create a new sibling
			// and insert on it.
			else
			{
				temp->sibling = new Node(currentLetter);
				temp->sibling->insert(word);
				return true;
			}

		}

		// We found the node we're looking for. If it doesn't have a child,
		// create one. In both cases, insert on the child.
		if (!temp->child)
		{
			temp->child = new Node();
		}

		temp->child->insert(word.substr(1));
		return true;
	}

	return false;
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
	std::cout << "---Trie contents---\n" << std::endl;

	root.display();

}
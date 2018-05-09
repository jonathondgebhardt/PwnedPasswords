#include "stdafx.h"
#include "Trie.h"
#include <string>
#include <iostream>

#define EMPTYNODE '!'
#define HASHLENGTH 4

Trie::Trie()
{
	root = Node();
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
void Trie::insert(std::string word)
{
	// Base case: sha1sum is a 40 char string
	if (word.length() != HASHLENGTH)
	{
		return;
	}

	char currentLetter = (char)word[0];

	// If trie is empty, we don't need to look for an appropriate
	// node since there are none.
	if (!root.child)
	{
		root.child = new Node(currentLetter);
		root.child->child = new Node();
		root.child->child->insert(word.substr(1));
	}

	// Otherwise, we look for an appropriate node to insert on
	Node* temp = root.child;
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
			temp->sibling->child = new Node();
			temp->sibling->child->insert(word.substr(1));
		}
	}

	// We found the node we're looking for. If it doesn't have a child,
	// create one. In both cases, insert on the child.
	if (!temp->child)
	{
		temp->child = new Node();
	}

	temp->child->insert(word.substr(1));
}

/*
Return the number of words in the trie
*/
int Trie::getWordCount()
{
	// Base case: no words in trie yet
	if (!root.child)
	{
		return 0;
	}

	// Otherwise, start counting at root's child
	return root.child->getWordCount();
}

/*
Return the total number of nodes in the trie
*/
int Trie::getSize()
{
	// Base case: no words in trie yet
	if (!root.child)
	{
		return 0;
	}

	// Otherwise, start counting at root's child
	return root.child->getSize();
}

/*
If the given word is in the trie, return true, otherwise return false
*/
bool Trie::find(std::string word)
{
	// Base case: word length is invalid or no words in trie
	if (word.length() != HASHLENGTH || !root.child)
	{
		return false;
	}

	// Word is appropriate size, so we can start looking
	char currentLetter = (char)word[0];
	
	// Iterate over all of root child's siblings
	Node* temp = root.child;
	while (temp)
	{
		// If the current node has the value we're searching for,
		// we recurse.
		if (temp->value == currentLetter)
		{
			return temp->child->find(word.substr(1));
		}

		temp = temp->sibling;
	}

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
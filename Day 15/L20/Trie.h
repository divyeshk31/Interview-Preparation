#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.h"
class Trie {

	TrieNode* root;
	int numWords;

	bool deleteWord(TrieNode* node, char* word) {
		if (word[0] == '\0') {
			if (!node->isTerminal) {
				return false;
			}

			node->isTerminal = false;
			return true;
		}

		TrieNode* child = node->getChildForChar(word[0]);
		if (child == NULL) {
			return false;
		}
		bool output = deleteWord(child, word + 1);
		if (!child->isTerminal && child->childCount() == 0) {
			node->deleteChild(child->data);
		}
		return output;
	}

	bool addWord(TrieNode* node, char* word) {
		if (word[0] == '\0') {
			if (node->isTerminal) {
				return false;
			}

			node->isTerminal = true;
			return true;
		}

		TrieNode* child = node->getChildForChar(word[0]);
		if (child == NULL) {
			child = new TrieNode(word[0]);
			node->setChild(child);
		}
		
		return addWord(child, word + 1);
	}

	public:
	Trie() {
		root = new TrieNode('\0');
		numWords = 0;
	}
	
	int numberWords() {
		return numWords;
	}

	void deleteWord(char* word) {
		if (deleteWord(root, word)) {
			numWords--;
		}
	}

	bool findWord(char* word) {
		TrieNode* currentNode = root;
		for (int i = 0; word[i] != '\0'; i++) {
			TrieNode* child = currentNode->getChildForChar(word[i]);
			if (child == NULL) {
				return false;
			}
			currentNode = child;
		}
		return currentNode->isTerminal;
	}

	void addWord(char* word) {
		bool added = addWord(root, word);
		if (added)
			numWords++;
	}

	~Trie() {
		delete root;
	}
};
#endif;

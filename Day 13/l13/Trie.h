#include <unordered_map>
using namespace std;

class TrieNode {

	public:
		char data;
		map<char, TrieNode*> children;
		bool isTerminal;

	TrieNode(char data) {
		this->data = data;
	}

};

class Trie {
	TrieNode* root;
	int numWords;
	public:
	Trie() {
		root = new TrieNode('\0');
		numWords = 0;
	}

	bool contains(string word) {

	}

	void remove(string word) {

	}

	private:
	static bool insert(TrieNode* node, string word, int index) {
		if (index == word.size()) {
			if (node->isTerminal)
				return false;

			node->isTerminal = true;
			return true;
		}

		char currentChar = word[index];
		TrieNode* nextNode = node->children[currentChar];
		if (nextNode == NULL) {
			nextNode = new TrieNode(currentChar);
			node->children[currentChar] = nextNode;
		}
		return insert(nextNode, word, index + 1);
	}

	public:
	void insert(string word) {
		if(insert(root, word, 0))
			numWords++;
	}






};

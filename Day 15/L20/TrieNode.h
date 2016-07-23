#ifndef TRIENODE_H
#define TRIENODE_H
class TrieNode {
	TrieNode** children;
	public:
	char data;
	bool isTerminal;
	TrieNode(char data) {
		isTerminal = false;
		this->data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}

	int childCount() {
		int count = 0;
		for (int i = 0; i < 26; i++) {
			if (children[i] != NULL)
				count++;
		}
		return count;
	}

	~TrieNode() {
		for (int i = 0; i < 26; i++) {
			if (children[i] != NULL) {
				delete children[i];
			}
		}
		delete [] children;
	}

	void deleteChild(char c) {
		if (children[c - 'a'] != NULL) {
			delete children[c - 'a'];
		}

		children[c - 'a'] = NULL;
	}

	void setChild(TrieNode* child) {
		if (child == NULL) {
			return;
		}
		if (children[child->data - 'a'] != NULL) {
			delete children[child->data - 'a'];
		}
		children[child->data - 'a'] = child;
	}

	TrieNode* getChildForChar(char c) {
		return children[c - 'a'];	
	}

};
#endif

#include <cstring>

class HashNode {
	public:
	char* key;
	int value;
	HashNode* next;
	HashNode(char* key, int value) {
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
		this->value = value;
		next = NULL;
	}

	~HashNode() {
		delete [] key;
		if (next != NULL) {
			delete next;
		}
	}
}

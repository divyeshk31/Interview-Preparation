#include "HashNode.h"

class map {
	int capacity;
	HashNode** buckets;
	int size;

	int getBucketIndex(char* key) {
		int currentPower = 1;
		int currentSum = 0;
		int i = strlen(key) - 1;
		for (; i >= 0; i--) {
			currentSum = currentSum + currentPower * key[i];
			currentPower = (31 * currentPower) % capacity;
			currentSum = currentSum % capacity;
		}
		return currentSum % capacity;
	}

	public:
	map() {
		capacity = 13;
		size = 0;
		buckets = new HashNode*[capacity];
		for (int i = 0; i < capacity; i++) {
			buckets[i] = NULL;
		}
	}

	~map() {
		for (int i = 0; i < capacity; i++) {
			if (buckets[i] != NULL) {
				delete buckets[i];
			}
		}
		delete [] buckets;
	}

	void deleteKey(char* key) {
		int index = getBucketIndex(key);
		HashNode* head = buckets[index];
		HashNode* prev = NULL;
		while (head != NULL) {
			if (strcmp(head->key, key) == 0) {
				break;
			}
			prev = head;
			head = head->next;
		}
		if (head == NULL) {
			return;
		}
		size--;
		if (prev != NULL) {
			prev->next = head->next;
		} else {
			buckets[index] = head->next;
		}
		head->next = NULL;
		delete head;
	}

	int find(char* key) {
		int index = getBucketIndex(key);
		HashNode* head = buckets[index];
		while (head != NULL) {
			if (strcmp(head->key,key) == 0) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	void insert(char* key, int value) {
		int index = getBucketIndex(key);
		HashNode* head = buckets[index];
		while (head != NULL) {
			if (strcmp(head->key,key) == 0) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		size++;	
		HashNode* newNode = new HashNode(key, value);
		newNode->next = buckets[index];
		buckets[index] = newNode;
	}

};

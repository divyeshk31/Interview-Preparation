#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
	vector<string> vertices;
	unordered_map<string, vector<string>*> edges;

	public:
	bool hasVertex(string a) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i] == a) {
				return true;
			}
		}
		return false;
	}

	private:
	bool hasPathHelper(string a, string b,
			unordered_set<string>& visited) {
		
		if (hasEdge(a, b)) {
			return true;
		}
		visited.insert(a);

		vector<string>* adjacent = edges[a];
		for (int i = 0; i < adjacent->size(); i++) {
			if (visited.count(adjacent->at(i)) != 0) {
				continue;
			}	
			if (hasPathHelper(adjacent->at(i), b, visited)) {
				return true;
			}
		}
		return false;
	}

	public:
	bool hasPath(string a, string b) {
		if (!hasVertex(a) || !hasVertex(b)) {
			return false;
		}
		unordered_set<string> visited;
		return hasPathHelper(a, b, visited);
	}

	/*
	void removeVertex(string a) {
		if (!hasVertex(a)) 
			return;

		vertices.erase(vertices.find(a));
	}
	*/

	void addEdge(string a, string b) {
		if (!hasVertex(a) || !hasVertex(b)) {
			return;
		}
		if (hasEdge(a, b)) {
			return;
		}
		
		edges[a]->push_back(b);
		edges[b]->push_back(a);

	}

	bool hasEdge(string a, string b) {
		if (!hasVertex(a) || !hasVertex(b)) {
			return false;
		}
		if (find(edges[a]->begin(), edges[a]->end(), b) 
				!= edges[a]->end()) {
			return true;
		} else {
			return false;
		}
	}

	void addVertex(string a) {
		if (hasVertex(a))
			return;
		vertices.push_back(a);
		edges[a] = new vector<string>();
	}

};

int main() {
	Graph g;	
}

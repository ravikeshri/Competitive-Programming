#include <bits/stdc++.h>

using namespace std;

class disjSet {

	int n; // no of elements
	int *parent; //parent[i] = i for a root node
	int *size; // size of each component
	int components; // no of components

	public:
		disjSet(int n) {
			if(n <= 0)
				throw invalid_argument("Invalid Size"); // exception handling

			this->n = n;
			this->components = n; // initially all are distinct components
			parent = new int[n];
			size = new int[n];

			for(int i=0; i<n; i++) {
				parent[i] = i; // self root (initially)
				size[i] = 1; // n components each of size 1 (intially)
			}
		}

		// find component of p
		// components are classified by their parents
		// each component have only one root
		int find(int p) {

			// find root of p
			int root = p;
			while(root != parent[root])
				root = parent[root];

			// path compression:
			// making immediate parent of each node
			// of the component as root
			while(p != root) {
				int tmp = parent[p];
				parent[p] = root;
				p = tmp;
			}

			return root;
		}

		// unify the two components with nodes p and q
		void Union(int p, int q) {
			int pRoot = find(p);
			int qRoot = find(q);

			// same component, do nothing
			if(pRoot == qRoot)
				return;

			// merge smaller component to the larger one
			if(size[pRoot] < size[qRoot]) {
				size[qRoot] += size[pRoot];
				parent[pRoot] = qRoot;
			}
			else {
				size[pRoot] += size[qRoot];
				parent[qRoot] = pRoot;
			}

			// reduce no. of components by 1
			components--;
		}

		// to check whether p and q belongs to
		// same component or not
		bool connected(int p, int q) {
			return find(p) == find(q);
		}

		// no of nodes in the component having p
		int componentSize(int p) {
			return size[find(p)];
		}

		// no of components
		int noOfComponents() {
			return components;
		}

		// no of nodes
		int nodes() {
			return n;
		}
};

int main() {
	disjSet Graph(5);
    Graph.Union(0, 2);
    Graph.Union(4, 2);
    Graph.Union(3, 1);
    if (Graph.connected(0, 4))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (Graph.connected(1, 0))
        cout << "Yes\n";
    else
        cout << "No\n";
	cout << "No. of components: " << Graph.noOfComponents() << "\n";
	cout << "Component size having node 0: " << Graph.componentSize(0) << "\n";
    return 0;
}

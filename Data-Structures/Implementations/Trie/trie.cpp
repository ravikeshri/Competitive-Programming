#include<bits/stdc++.h>
#define MAX 100005
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int, int>
#define tc ll t; cin >> t; while(t--)
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

struct TrieNode {
	char data;
	int we; // word-end(no of words ending at this node)
	TrieNode *child[26];
	
	TrieNode(char data = '\0') {
		this->data = data;
		this->we = 0;
		
		for(int i=0; i<26; i++) {
			child[i] = NULL;
		}
	}
};

void insert(TrieNode *root, string s) {
	
	int n = s.length();
	
	for(int i=0; i<n; i++) {
		
		int pos = s[i] - 'a';
		if(root->child[pos] == NULL) {
			root->child[pos] = new TrieNode(s[i]);
		}
		
		root = root->child[pos];
	}
	root->we += 1;
}

// returns numbers of word s in Trie
int search(TrieNode *root, string s) {
	
	int n = s.length();
	
	for(int i=0; i<n; i++) {
		
		int pos = s[i] - 'a';
		if(root->child[pos] == NULL) {
			return -1;
		}
		
		root = root->child[pos];
	}
	
	if(root->we > 0) {
		return root->we;
	} else {
		return -1;
	}
}

void del(TrieNode *root, string s) {
	
	int n = s.length();
	
	for(int i=0; i<n; i++) {
		
		int pos = s[i] - 'a';
		if(root->child[pos] == NULL) {
			return;
		}
		
		root = root->child[pos];
	}
	
	if(root->we > 0) {
		// delete all occurance of s
		// root->we = 0;
		
		// delete single occurence of s
		root->we -= 1;
	}

}

int main() {
    fast;
	
	TrieNode *p = new TrieNode();
	
	insert(p, "abc");
	insert(p, "abd");
	insert(p, "ab");
	insert(p, "efgh");
	insert(p, "ab");
	
	cout << search(p, "abc") << endl;
	del(p, "abc");
	cout << search(p, "abc") << endl;
	
	cout << search(p, "ab") << endl;
	del(p, "ab");
	cout << search(p, "ab") << endl;
	
	cout << search(p, "abcde") << endl;
	del(p, "abcde");
	cout << search(p, "abcde") << endl;
	
	cout << search(p, "a") << endl;
	del(p, "a");
	cout << search(p, "a") << endl;
	
	cout << search(p, "xyz") << endl;
	del(p, "xyz");
	cout << search(p, "xyz") << endl;
	
	// debug(p->data);
	
    return 0;
}

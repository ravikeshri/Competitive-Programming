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

int limit;

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

void suggestRec(TrieNode *root, string& op) {

	if(limit == 0) {
		return;
	}

	if(root->we > 0) {
		limit--;
		cout << op << ", ";
	}
	
	
	for(int j=0; j<26; j++) {
		if(root->child[j]) {
			op.push_back(root->child[j]->data);
			suggestRec(root->child[j], op);
			op.pop_back();
		}
	}
	
}

void suggestions(TrieNode *root, string s) {
	
	int n = s.length();
	string op = "";
    
	for(int i=0; i<n; i++) {
		
        limit = 3;
        // currRes.clear();
        
		int pos = s[i] - 'a';
		if(root->child[pos] == NULL) {
			cout << "No string matches afterwords";
            // currRes.push_back("");
			return;
		}
		
		root = root->child[pos];
        
        op = op + s[i]; 
        cout << "Entered " << op << " : ";
        suggestRec(root, op);
        
        // res.push_back(currRes);
        cout << endl;
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
	
	suggestions(p, "abcde");
	
    return 0;
}

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

vi arr[MAX];
int parent[MAX];
int disc[MAX];
int low[MAX];
bool art[MAX];
int t;

// no need of visited array, disc will do the work

void dfs(int p) {
	disc[p] = t;
	low[p] = t;
	t++;
	
	int child = 0;
	for(int v: arr[p]) {
		if(disc[v] == -1) { // v is not visited
			child++;
			parent[v] = p;
			dfs(v);
			low[p] = min(low[p], low[v]);
			
			if(parent[p] == -1 && child > 1) {
				art[p] = true;
			}
			if(parent[p] != -1 && disc[p] <= low[v]) {
				art[p] = true;
			}
		} else {
			if(v != parent[p]) {
				low[p] = min(low[p], disc[v]);
			}
		}
	}
}

void reset(int n) {
	for(int i=1; i<=n; i++) {
		arr[i].clear();
		parent[i] = -1;
		disc[i] = -1;
		low[i] = -1;
		art[i] = false;
	}
	t = 0;
}

int main() {
    fast;
	
	int n, m;
	cin >> n >> m;
	
	reset(n);
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	for(int i=1; i<=n; i++) {
		if(disc[i] == -1) {
			dfs(i);
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(art[i]) {
			cout << i << ", ";
		}
	}
	
    return 0;
}

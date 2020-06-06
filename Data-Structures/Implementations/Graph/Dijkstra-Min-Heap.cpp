#include<bits/stdc++.h>
#define ll long long
#define MAX 105
#define pb push_back
#define pll pair<ll, ll>

using namespace std;

vector<vector<pll> > g(MAX);
ll dis[MAX];

void dijkstra(ll s) {
    fill(dis, dis+MAX, INT_MAX);
    
    // min-heap
    priority_queue<pll, vector<pll>, greater<pll> > q;
    
    // first value must be weight to sort according to weight
    q.push({0, s});
    dis[s] = 0;
    
    ll u, v, w;
    while(!q.empty()) {
        u = (q.top()).second;
        q.pop();
        
        for(ll i=0; i<(ll)g[u].size(); i++) {
            v = g[u][i].second;
            w = g[u][i].first;
            
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll a, b, w;
    while(m--) {
        cin >> a >> b >> w;
        g[a].pb({w, b});
        g[b].pb({w, a});
    }
    
    dijkstra(1);
    
    for(ll i=1; i<=n; i++) {
        cout << i << " --> " << dis[i] << "\n";
    }
    
    return 0;
}

/* 
input: 

9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 10
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/

/*
output: 

1 --> 0
2 --> 4
3 --> 12
4 --> 19
5 --> 21
6 --> 11
7 --> 9
8 --> 8
9 --> 14
*/
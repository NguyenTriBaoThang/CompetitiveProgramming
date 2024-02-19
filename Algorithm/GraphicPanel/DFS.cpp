#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
#define sz(x) (int)(x).size()

int n, m, s, t;
bool visitDFS[N];
vector<int> adj[N];
vector<int> trace(N,-1);

void dfs(int u) {
	visitDFS[u] = true;
	for (int v : adj[u]) {
		if (!visitDFS[v]){
			trace[v] = u;
			dfs(v);
		}
    }
}

//Truy vết
vector<int> trace_path(int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(0); // không có đường đi

    vector <int> path;
    while (u != -1) { // truy vết ngược từ u về S
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end()); 
    
    return path;
}

void solve(){
	cin >> n >> m >> s >> t;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
	fill_n(visitDFS, n + 5, false);
	dfs(s);
	
 	vector <int> path = trace_path(s,t);
    if(sz(path) == 1){
    	cout << "-1";
	}else{
		cout << sz(path) - 1 << '\n';
    	for (auto v : path) 
			cout << v << ' ';
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
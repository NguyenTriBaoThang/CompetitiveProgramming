#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
#define sz(x) (int)(x).size()

int n, m, s, t, components = 0;
vector<int> trace(N,-1);
bool visitBFS[N];
vector<int> g[N];

void bfs(int s) {
    ++components;
    queue <int> q;
    q.push(s);
    visitBFS[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visitBFS[v]) {
                visitBFS[v] = true;
                trace[v] = u;
                q.push(v);
            }
        }
    }
}

//Truy vết
vector<int> trace_path(int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(0); // không có đường đi

    vector<int> path;
    while (u != -1) { // truy vết ngược từ u về S
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end()); // cần reverse vì đường đi lúc này là từ u về S
    
    return path;
}

void solve(){
	cin >> n >> m >> s >> t;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill_n(visitBFS, n + 1, false);
    for (int i = 1; i <= n; ++i)
        if (!visitBFS[i]) bfs(i);
    cout << components;
    
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
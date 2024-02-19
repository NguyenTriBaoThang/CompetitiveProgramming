#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const long long INF_LL = 2000000000000000000LL;
#define sz(x) (int)(x).size()

struct Edge{// kiểu dữ liệu tự tạo để lưu thông số của một cạnh.
    int v;
    long long w;
};

struct Node{// kiểu dữ liệu để lưu đỉnh u và độ dài của đường đi ngắn nhất từ s đến u.
    int u;
    long long Dist_u;
};

struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

int n, m, s, t;
vector<vector<Edge>> E(N);
vector<long long> minPath(N, INF_LL);
vector<int> trace(N,-1);


void dijkstraSparse() {
    vector<bool> P(n, 0);
    
    minPath[s] = 0;
    priority_queue<Node, vector<Node>, cmp> h; // hàng đợi ưu tiên, sắp xếp theo dist[u] nhỏ nhất trước
    h.push({s, minPath[s]});
    
    while(!h.empty()) {
        Node x = h.top();
        h.pop();
        
        int u = x.u;
        if(P[u] == true) // Đỉnh u đã được chọn trước đó, bỏ qua
            continue;
            
        P[u] = true; // Đánh dấu đỉnh u đã được chọn
        for(auto e : E[u]) {
            int v = e.v;
            long long w = e.w; 
            
            if(minPath[v] > minPath[u] + w) {
                minPath[v] = minPath[u] + w;
                h.push({v, minPath[v]});
                trace[v] = u;
            }
        }
    }
}

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
        int u, v;  long long w; 
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    
    dijkstraSparse();
    
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
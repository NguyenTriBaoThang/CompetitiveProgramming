#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n=0; cin >> n;
    if(n <= 3) cout << n << endl;
    else if(n <= 6) cout << 3 << endl;
    else cout << 4 << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
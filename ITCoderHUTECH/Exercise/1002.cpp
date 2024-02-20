#include<bits/stdc++.h>
typedef long long ll;

// https://itcoder.hutech.edu.vn/p/1002

bool checkYear(int n){
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return true;
    return false;
}

void solve(){
    ll T=0; cin >> T;
    while(T--){
        ll n=0; cin >> n;
        if(checkYear(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}

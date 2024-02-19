#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s; fflush(stdin); getline(cin,s);
    stringstream ss(s);
    string tmp;
    while(ss >> tmp) cout << tmp.size() << " ";
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
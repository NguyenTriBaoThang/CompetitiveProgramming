#include<bits/stdc++.h>
using namespace std;

//Demo factorial (tính giai thừa)

int n;

long long recursion(int n){
    if (n == 0) return 1;    //trường hợp cơ sở
    return recursion(n - 1) * n;    //phần đệ quy
}

void solve(){
	cin >> n;
	cout << recursion(n);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
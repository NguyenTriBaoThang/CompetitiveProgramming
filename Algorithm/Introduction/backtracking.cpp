#include<bits/stdc++.h>
using namespace std;

//Demo Sinh các dãy nhị phân

int n;
string curString;

void backtrack(int pos){
	// Trường hợp cơ sở
    if (pos > n){ // <pos là vị trí cuối cùng>
    	//<output/lưu lại tập hợp đã dựng nếu thoả mãn>
        cout << curString << "\n";
        return;
    }
    
    //Phần đệ quy
    for (char i = '0'; i <= '1'; i ++){ // for (<tất cả giá trị i có thể ở vị trí pos>)
    	//<thêm giá trị i vào tập đanh xét> thêm ký tự mới vào dãy
        curString.push_back(i);
        backtrack(pos + 1);
        //<xoá bỏ giá trị i khỏi tập đang xét> bỏ ký tự này đi
        curString.pop_back();
    }
}

void solve(){
	cin >> n;
    curString = "";
    backtrack(1);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
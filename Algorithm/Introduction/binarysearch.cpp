#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Linear Search: Tim kiem 1 gia tri nao do trong mang thi no chay tu dau toi cuoi de so khop
// Duyet tat ca phan tu trong mang o(n)
// 10 3
// 1 2 8 9 10 0 7 6 2 3 
bool ls(int a[],int n, int x){
	for(int i=0;i<n;i++){
		if(a[i]==x)return true;
	}
	return false;
}

// Binary search do phuc tap o(log(n)) tim kiem trong 1 mang hoac vector phan tu trong mang phai duoc sap xep tang dan hoac giam dan
// Thi moi ap dung duoc tim kiem nhi phan

// Cach thong thuong
bool bs(int a[], int n, int x){
	int l=0, r = n-1;
	while(l<=r){
		int m = (l+r)/2; // l + (r-l) /2
		if(a[m] == x) return true;
		else if(a[m] < x){
			// Thang dung giua nho hon x, tim o ben phai, l = m+1
			l = m+1;
		}else if(a[m] < x){
			// Phai tim o ben trai, r=m-1
		}else{
			r = m-1;
		}
	}
	return false;
}

// Cach de quy
bool binary_search_de_quy(int a[], int l, int r, int x){
	if(l > r) return false;
	int m = (l+r)/2;
	if(a[m] == x) return true;
	else if(a[m]<x)
		return binary_search_de_quy(a, m+1, r, x);
	else
		return binary_search_de_quy(a, l, m-1, x);
}

// binary_search(a+x, a+y, key) => a[x] => a[y-1]
// binary_search(a+1, a+4, key)
// binary_search(v.begin(), v.end(), key)
// binary_search(b.begin()+x, v.begin()+y, key) => v[x]=>v[y-1]

// Tim vi tri dau tien cua 1 phan tu x trong 1 mang da sap xep
int first_pos(int a[], int n, int x){
	int res = -1;
	int l=0,r=n-1;
	while(l<=r){
		int m = (l+r)/2;
		if(a[m] == x){
			res = m;
			// Tim them o ben trai xem con khong?
			r = m-1;
		}else if(a[m] < x){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	return res;
}

// Vi tri cuoi cung
int last_pos(int a[], int n, int x){
	int res = -1;
	int l=0,r=n-1;
	while(l<=r){
		int m = (l+r)/2;
		if(a[m] == x){
			res = m;
			// Tim them o ben phai coi con khong?
			l = m+1;
		}else if(a[m] < x){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	return res;
}

// lower_bound(iter1, iter2, key) {iter1, iter2} => tra ve vi tri cua phan tu dau tien >= key
// Tim kiem trong doan iter1 den truoc vi tri iter2
// Neu ma tat ca cac phan tu trong mang deu nho hon key => iter2
// upper_bound(iter1, iter2, key) {iter1, iter2} => tra ve vi tri dau tien cua phan tu > key
// Neu ma tat ca cac phan tu trong mang deu nho hon key => iter2
int main(){
	int n, x; 
    cin >> n >> x;

	int a[n];
	for(int i=0;i<n;i++) 
        cin >> a[i];

	if(bs(a,n,x)) cout << "FOUND!"<<endl;
	else cout << "NOT FOUND!" << endl;

	// a la phan tu tro den dau tien va a+n la phan tu tro den phan tu cuoi cung
	// Dung ham co san binary_search
	if(binary_search(a, a+n,x)) cout << "FOUND!"<<endl;
	else cout << "NOT FOUND!" << endl;

	// dvs vector
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	if(binary_search(v.begin(), v.end(), x)) cout << "FOUND!"<<endl;
	else cout << "NOT FOUND!" << endl;

	// Tim so lan xuat hien
	int l = first_pos(a, n, x);
	int r = last_pos(a, n, x);
	if(l != -1) cout << r-l+1 <<endl;
	else cout << "NOT FOUND!" << endl;

	//lower_bound ap dung trong mang dc sap xep roi duoc ap dung trong mang, vecter, set , map
	auto it = lower_bound(a, a+n, x);
	cout << *it << endl;

	// int ra chi so
	cout << it - a << endl;
	if(it == (a+n)) cout << "Khong co phan tu nao trong mang >= " << x << endl;

	//upder_bound
	auto it1 = upper_bound(a, a+n, x);
	cout << *it1 << endl;
    
	return 0;
}

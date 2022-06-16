#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("test10.inp", "r", stdin);
	int n, total = 0;cin>>n;
	cin.ignore();
	string s,h;
	getline(cin, s);
	for (int i = 0 ; i< s.length(); i++){
		int x; cin>>x;
		total+=x*(s[i] - '0');
	}
	cin.ignore();
	getline(cin, h);
	cout<<h[total%n];
}
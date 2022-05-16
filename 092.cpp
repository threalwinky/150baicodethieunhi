#include <bits/stdc++.h>
using namespace std;
char gt[2000];
int m,n,a = 0,b = 0;
ifstream file("fdigit.inp");
int factorialNumber(int x){
	if (x == 0 || x == 1) return 1;
	for (int i = 0; i < 2000; i++)
	{
		gt[i] = '0';
	}
	gt[0] = '1';
	int i,j,temp = 0, len = 1;
	for (i = 2; i<=x; i++)
	{
		for (j = 0; j<len || temp != 0; j++)
		{
			temp += (gt[j] - '0') * i;
			gt[j] = temp%10 + '0';
			temp /= 10;
		}
		len = j;
	}
	return j;
}
void nhap(){
	file>>m>>n;
}
void xuly(){
	while (factorialNumber(a) < m){
		a++;
	}
	while (factorialNumber(b) < n){
		b++;
	}
	if (m == n) b--;
}
void xuat(){
	cout<<a<<" "<<b;
}
int main(){
	nhap();
	xuly();
	xuat();
}
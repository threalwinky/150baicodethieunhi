#include <bits/stdc++.h>
using namespace std;
#define NMAX 1001
string m1,n1;
char m[NMAX],n[NMAX];
int a[255],b[255], ml, nl, temp = 1;
string s[NMAX];
void inp()
{
	getline(cin, m1);
	getline(cin, n1);
	ml = m1.length();
	nl = n1.length();
	for (int i = 0; i<ml; i++) m[i] = m1[i];
	for (int i = 0; i<nl; i++) n[i] = n1[i];
}
void outans()
{
	for (int i = 0; i<ml; i++) cout<<m[i];
	for (int i = 0; i<nl; i++) cout<<n[i];
}
void change_obj()
{
	for (int i = 0; i<m1.length(); i++) a[m[i]]++;
	for (int i = 0; i<n1.length(); i++) b[n[i]]++;
	for (int i = 0; i<255; i++)
	{
		if (a[i] != b[n[i]]) a[i] = min(a[i], b[i]);
	}
	for (int i = 0; i<m1.length(); i++) 
	{
		if (a[m[i]] == 0 && a[n[i]] == 0 && n[i]!=0){
			s[temp] += '1';
			s[temp] += ' ';
			s[temp] +=  (i+1+'0');
			s[temp] += ' ';
			s[temp] += n[i];
			m[i] = n[i];
			temp++;
		}
	}
}
void change_pos()
{
	for (int i = 0; i<m1.length(); i++) 
	{
		for (int j = 0; j<m1.length(); j++) 
		{
			if (i!=j && a[m[i]] > 0 && a[m[j]] > 0 && m[i] != n[i] && m[j] != n[j]){
				s[temp] += '2';
				s[temp] += ' ';
				s[temp] +=  (i+1+'0');
				s[temp] += ' ';
				s[temp] +=  (j+1+'0');
				temp++;
				char temp = m[i];
				m[i] = m[j];
				m[j] = temp;
				a[m[i]]--;
				a[m[j]]--;
				
			}
		}
	}
}
void delete_obj()
{
	for (int i = 0; i<m1.length(); i++) 
	{
		if (a[m[i]] == 0 && a[n[i]] != 0){
			for (int j = i; j<m1.length(); j++){
				m[j] = m[j+1];

			}
			s[temp] += '4';
			s[temp] += ' ';
			s[temp] +=  (i+'0');
			temp++;
		}
	}
	ml--;
}
void insert_obj()
{
	for (int i = 0; i<m1.length(); i++) 
	{
		if (a[m[i]] != 0 && a[n[i]] == 0 && m[i] != n[i]){
			for (int j = m1.length()+1; j > i; j--){
				m[j] = m[j-1];
			}
			m[i] = n[i];
			s[temp] += '3';
			s[temp] += ' ';
			s[temp] +=  (i+'0');
			s[temp] += ' ';
			s[temp] += n[i];
			temp++;
		}
	}
	ml++;
}
void change()
{
	change_obj();
	change_pos();
	
	insert_obj();
	delete_obj();
}
void out()
{
	change();
	cout<<temp<<endl;
	for (int i = 1; i<=temp; i++){
		cout<<s[i]<<endl;
	}
}
int main(){
	inp();
	out();
}
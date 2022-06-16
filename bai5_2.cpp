#include <bits/stdc++.h>
using namespace std;

string fib(int n);
void kt(string str1, string str2);
int main()
{
    freopen("fibistr.inp", "r", stdin);
    while (!cin.eof()){
    int n; cin>>n;
    cin.ignore();
    string str1;
    getline(cin,str1);
    string str2 = fib(n);
    kt(str1, str2);
    }
}
string fib(int n)
{
    if (n==1) return "A";
    else{
    string f[n];
    f[0] = "A";f[1] = "B";
    for(int i = 2; i < n; i++)
        f[i] = f[i-1] + f[i-2];
    string str2 = f[n-1];
    return str2;
    }
}
void kt(string str1, string str2)
{
    int a = (str2.size() - str1.size());
    map<string,int> mp;
    do
    {
        mp[str2.substr(0,str1.size())]++;
        str2.erase(0,1);
    }while(a--);
    cout<<mp[str1]<<endl;
}
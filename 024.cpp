#include<bits/stdc++.h>
using namespace std;
string rvs(string str)
{
    string strrvs;
    for (int i = str.length()/2; i<str.length(); i++)
        strrvs += str[i];
    for (int i = 0; i<str.length()/2; i++)
        strrvs += str[i];

    return strrvs;
}
int main(){
    long long int n, m;
    freopen("024.inp", "r", stdin);
    cin>>n>>m;
    string s = "10";
    for (int i = 1; i<n;i++){
        s+=rvs(s);
    }
    cout<<s[m-1];
}
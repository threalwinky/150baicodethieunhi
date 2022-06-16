#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("024.inp", "r",stdin);
    string s = "10", srv = "01";
    bool check = 0;
    int m,n,temp;
    cin>>n>>m;
    temp = m;
    int i = (1<<n);
    while (i>2){
        i/=2;
        if (m>i) {
            check = !check;
            m-=i;
        }
    }
    if (check) cout<<s[temp%2];
    else cout<<srv[temp%2];
}
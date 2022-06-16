#include <bits/stdc++.h>
using namespace std;
void hv(int &m, int &n){
    int temp = m;
    m = n;
    n = temp;
}
int main(){
    int a,b;
    cin>>a>>b;
    hv(a,b);
    cout<<a<<b;
}
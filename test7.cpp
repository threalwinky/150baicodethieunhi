#include <bits/stdc++.h>
using namespace std;
int n,x,it = 0,total = 0;
vector<int> v[1001];
void inp(){
    cin >> n >> x;
    for (int i = 0; i<n;i++){
        int a,b;
        cin>>a>>b;
        if ((abs(a-b)) <= x) total+=max(a,b);
        else {
            int c;
            cin>>c;
            total+=c;
        }
    }
}
void out(){
    cout<<total;
}   
int main(){
    inp();
    out();
}
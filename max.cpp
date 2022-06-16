#include<bits/stdc++.h>
using namespace std;
#define NMAX 1001
int m,n,max1[NMAX],maxvt1[NMAX],x, total = 0;
void inp(){
    memset(max1, -10000,NMAX);
    cin>>m>>n;
    for (int i = 1; i<=m; i++){
        for (int j = 1 ;j<=n;j++){
            cin>>x;
            if (x>max1[j]){
                max1[j] = x;
                maxvt1[j] = i;
            }
        }
    }
}
void out(){
    for (int i = 1; i<=n;i++) total+=max1[i];
        cout<<total<<endl;
    for (int i = 1; i<=n;i++) cout<<maxvt1[i]<<endl;
}
int main(){
    inp();
    out();
}
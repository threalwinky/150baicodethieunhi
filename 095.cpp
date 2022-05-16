#include<bits/stdc++.h>
using namespace std;
int a[1000],tama[1000],b[1000],tamb[1000], m, n, total;
ifstream file("buy.inp");
void nhap(){
    file>>m;
    file>>n;
    for (int i = 0; i<n; i++){
        file>>a[i]>>b[i];
        tama[i] = a[i];
        tamb[i] = b[i];
    }
}
void xuly(){
    float min;
    int temp;
    while (m!=0){
        min = 100000;
        for (int i = 0; i<n; i++){
            if (b[i] <= min) {
                min = b[i];
                temp = i;

            }
        }
        if (m - a[temp] >= 0){
        b[temp] = 10000000;
        m-=a[temp];
        a[temp]-=tama[temp];
        }
        else {
            a[temp]-=m;
            m = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        a[i] = tama[i] - a[i];
        total += a[i]*tamb[i];
    }
}
void xuat(){
    cout<<total<<endl;
    for (int i = 0; i<n; i++){
        cout<<a[i]<<endl;
    }
}
int main(){
    nhap();
    xuly();
    xuat();
}
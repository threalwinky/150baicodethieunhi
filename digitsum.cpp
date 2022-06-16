#include<bits/stdc++.h>
using namespace std;
#define NMAX 30
int n,k,p,temp1 = 1;
char a[NMAX],b[NMAX],so1[NMAX];
void inp(){
    cin>>n>>k>>p;
    memset(a,'0',NMAX);
    memset(b,'0', NMAX);
    memset(so1, '0', NMAX);
    a[0] = '1';
    so1[0] = '1';
}
int charlen(char x[]){
    int temp;
    for (int i = NMAX - 1; i>=0;i--){
        if (x[i] != '0'){
        temp = i;
        break;
        }
    }
    if (temp == 32767) return 0;
    else return temp+1;
}
bool check(char x[]){
    int temp = 0;
    for (int i = charlen(x) - 1; i>=0 ;i--){
        temp+=x[i]-'0';
    }
    if (temp == k) return true;
    else return false;
}
void add(char x[], char y[], char z[]){
    int i = charlen(x), j = charlen(y), sodu = 0, k = 0, d;
    while (j>0 || i>0 || sodu!=0){
        d = x[k]+y[k]-'0'-'0'+sodu;
        sodu = 0;
        while (d>=10){
            d%=10;
            sodu++;
        }
        z[k] = d+'0';
        i--;j--;k++;
    }
}
void outans(){
    for (int i = charlen(b) - 1; i>=0 ;i--){
        cout<<b[i];
    }
}
void out(){
    while (charlen(a) <= n){
    add(a,so1,a);
    if (temp1 == p) copy(begin(a),end(a),begin(b));
    if (check(a)){
            temp1++;
        }

    }
    
    cout<<temp1 - 1<<endl;
    outans();
}
int main(){
    freopen("digitsum.inp", "r", stdin);
    inp();
    out();
}
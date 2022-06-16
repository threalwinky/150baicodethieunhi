#include<bits/stdc++.h>
using namespace std;
#define NMAX 2000
char a[NMAX],a1[NMAX], b[NMAX], ans[NMAX], temp[NMAX], biendem[NMAX], tam[NMAX], so1[NMAX];
string m,n;
int charlen(char x[]){
    int temp;
    for (int i = NMAX - 1; i>=0;i--){
        if (x[i] != '0'){
        temp = i;
        return temp+1;
        break;
        }
    }
    return 1;
}
int ca = charlen(a), cb = charlen(b);
void inp(){
    cin>>m>>n;
    memset(a, '0', NMAX);
    memset(a1, '0', NMAX);
    memset(b, '0', NMAX);
    memset(ans, '0', NMAX);
    memset(temp, '0', NMAX);
    for (int i = m.length(); i>0; i--){
        a[m.length() - i] = m[i-1];
        a1[m.length() - i] = m[i-1];
    }
    for (int i = n.length(); i>0; i--){
        b[n.length() - i] = n[i-1];
    }
}
bool gtr(char x[], char y[]){
    for (int i = NMAX - 1; i>=0;i--){
        if ((x[i] == '0')&&(y[i]!='0')){
            return 0;
            break;
        }
        if ((x[i] != '0')&&(y[i]=='0')){
            return 1;
            break;
        }
        if ((x[i]!='0'&&y[i]!='0')&&(x[i] > y[i])){
            return 1;
            break;
        }
        if ((x[i]!='0'&&y[i]!='0')&&(x[i] < y[i])){
            return 0;
            break;
        }
        if (i == 0&&x[i]==y[i]) return 1;
    }
    return false;
}
void outans(){
    for (int i = charlen(ans) - 1; i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
}
void outtam(){
    for (int i = charlen(tam) - 1; i>=0;i--){
        cout<<tam[i];
    }cout<<endl;
}
void reset(){
    memset(ans, '0', NMAX);
}
void reset1(){
    memset(biendem, '0', NMAX);
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
void mul(char x[], int y, int z){
    int sodu = 0, d, i = 0;
    int cnt1 = charlen(x);
    while (cnt1>0||sodu!=0){
        d = (x[i]-'0')*(y)+sodu;
        sodu = d/10;
        while (d>=10){
            d%=10;
        }
        temp[z] = d+'0';
        cnt1--;i++;z++;
    }
}
void multiplicate(char x[], char y[], char z[]){
    for (int i = 0; i<charlen(y);i++){
        mul(x, y[i]-'0', i);
        add(z,temp, z);
        memset(temp, '0', NMAX);
    }
}
void subtract(char x[], char y[], char z[]){
    int i = charlen(x), j = charlen(y), sodu = 0, k = 0, d;
    while (j>0 || i>0 || sodu!=0){
        if (x[k] >= y[k]){
        d = x[k]-y[k];
        }
        else {
            d = x[k]-y[k]+10;
            x[k+1] = x[k+1] -1 ;
        }
        z[k] = d+'0';
        i--;j--;k++;
        }
}
void division(char x[], char y[], char z[]){
    memset(tam,'0', NMAX);
    memset(so1, '0', NMAX);
    memset(biendem, '0', NMAX);
    z[0] = '1';
    so1[0] = '1';
    while (true){
    multiplicate(y,z,biendem);
    if (gtr(biendem, x)){
        break;
        subtract(z, so1, tam);
    }
    add(z, so1, z);
    reset1();
    }
}
void module(char x[], char y[], char z[]){
    char tam1[NMAX];
    memset(tam1, '0', NMAX);
    multiplicate(tam, b, tam1);
    subtract(a, tam1, ans);
}
void out(){
    add(a,b,ans);
    outans();
    reset();
    subtract(a1,b,ans);
    outans();
    reset();
    multiplicate(a, b, ans);
    outans();
    reset();
    division(a, b, ans);
    subtract(ans, so1, tam);
    outtam();
    reset();
    module(a, b, ans);
    outans();
}
int main(){
    freopen("opt.inp", "r", stdin);
    inp();
    out();
}
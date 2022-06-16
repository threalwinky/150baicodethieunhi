
#include<bits/stdc++.h>
using namespace std;
int xc[255][255];
string str1,str2;
void truyhoi(int n, int m){
    if (m==0 || n==0) ;
    else {
        if (str1[n] == str2[m]) {
            cout<<str1[n-1];
            truyhoi(n-1,m-1);
        }else
        {

            if (xc[n-1][m] == xc[n][m]) truyhoi(n,m-1);
            else truyhoi(n-1,m);
        }
    }

}
int main(){
    ifstream file("str.inp");

    file>>str1;
    file>>str2;

    xc[0][0] = 0;
    for (int i = 1; i < str1.length()+1; i++){
        xc[i][0] = 0;
    };
    for (int i = 1; i < str2.length()+1; i++){
        xc[0][i] = 0;
    }
    for (int i = 1; i<str2.length()+1; i++)
        for (int j = 1; j<str1.length()+1; j++)
            if (str2[i-1] == str1[j-1])
            {
                xc[i][j] = xc[i-1][j-1] + 1;

            }
            else {
                if (xc[i-1][j]>=xc[i][j-1]) xc[i][j] = xc[i-1][j];
                else xc[i][j] = xc[i][j-1];
            }
    for (int i = 0; i<str2.length()+1; i++){
        for (int j = 0; j<str1.length()+1; j++)
        cout<<xc[i][j]<<" ";
        cout<<endl;
    }

    stack <char> temp;
    /*for (int i = str1.length()+1; i>=0; i--)
        for (int j = str2.length()+1; j>=0; j--)
            if (xc[i][j]>xc[i-1][j]&&xc[i][j]>xc[i][j-1]) truyhoi.push(str1[i]);
    for (int i = 0; i<xc[str2.length()][str1.length()]; i++){
        cout<<truyhoi.top();
        truyhoi.pop();
        }*/
    truyhoi(str1.length(),str2.length());

}

#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("str.inp");
    string str1,str2;
    file>>str1;
    file>>str2;
    int xc[255][255];
    xc[0][0] = 0;
    for (int i = 0; i < str1.length(); i++){
        xc[i+1][0] = 0;
    };
    for (int i = 1; i < str2.length(); i++){
        xc[0][i+1] = 0;
    }
    for (int i = 0; i<str1.length(); i++)
        for (int j = 0; j<str2.length(); j++)
            if (str1[i] == str2[j]) xc[i+1][j+1] = xc[i][j] + 1;
            else {
                if (xc[i][j+1]>xc[i+1][j]) xc[i+1][j+1] = xc[i][j+1];
                else xc[i+1][j+1] = xc[i+1][j];
            }
    for (int i = 0; i<str2.length()+1; i++){
        for (int j = 0; j<str1.length()+1; j++)
        cout<<xc[i][j]<<" ";
        cout<<endl;
    }
}

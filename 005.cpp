#include<bits/stdc++.h>
using namespace std;
int n;string s, fibiarr[36];
void lapfibiarr(){
    fibiarr[0] = "A";
    fibiarr[1] = "B";
    for (int i = 2; i<= 35 ; i++) fibiarr[i] = fibiarr[i-1] + fibiarr[i-2];
}
int demxc(string str2, string str1) {
    int temp = 0;
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == str1[0]) {
            int count = 0;
            for (int j = 0; j < str1.length(); j++) {
                if (str2[j + i] == str1[j])
                    count += 1;
            }
            if (count == str1.length())  temp++;
        }
    }
    return temp;
}
void xuat(){
    cout<<demxc(fibiarr[n-1] , s)<<endl;
}
int main(){
    ifstream file("fibistr.inp");
    lapfibiarr();
    while (!file.eof()){
        file>>n>>s;
        xuat();
    }
}
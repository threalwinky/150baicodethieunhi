#include <bits/stdc++.h>
using namespace std;
int dt(string s){
    int temp = 0;
    for (int i = 0;i<s.length();i++){
        int x = s[i] - '0';
        if (x == 0) temp+=4;
        else if (x%3 == 0){
        if (x%2==0) temp+=3;
        else temp+=1;
        }
        else temp +=2;
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    string h;
    cin>>n;
    for (int i = 0; i<n;i++){
        cin>>h;
        cout<<dt(h)<<endl;
    }
}
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n, temp = 0;
    stack <int> dec;
    cin>>n;
    if (n == 0) cout<<0;
    else {
    while (n!=0) {
        dec.push(n%2);
        n/=2;
    }
    while (!dec.empty()){
        cout<<dec.top();
        dec.pop();
    }
    }
}

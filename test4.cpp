#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, T, a, b;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++) {
        cin >> T;
        b += a;
        a = min(a, T);
    }
    cout << b;
}
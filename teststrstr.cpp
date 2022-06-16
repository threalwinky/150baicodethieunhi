#include<bits/stdc++.h>
using namespace std;
int isMatching(string T1, string T2) {
    int temp = 0;
    for (int i = 0; i < T2.length(); i++) {
        if (T2[i] == T1[0]) {
            int count = 0;
            for (int j = 0; j < T1.length(); j++) {
                if (T2[j + i] == T1[j])
                    count += 1;
            }
            if (count == T1.length())  temp++;
        }
    }
    return temp;
}


int main() {
    ifstream file("str.inp");
    string T1 ;
    string T2 ;
    file>>T1;
    file>>T2;
    cout <<T1<<" "<<T2 <<isMatching(T1, T2);
}
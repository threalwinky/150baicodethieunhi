#include <iostream>
using namespace std;
int d[10]={4,2,2,2,3,2,3,2,4,3};
int n[10]={2,0,3,3,1,3,3,1,3,3};
int so_gach_dung(int x,int y){
    int s=0;
    // Tìm số gạch đứng của giờ
    if (x < 10){
        s += d[x];
    } else {
        s += d[x % 10] + d[x / 10];
    }
    // Tìm số gạch đứng của phút
    if (y < 10){
        s += d[0] + d[y];
    } else {
        s += d[y % 10] + d[y / 10];
    }
    return s;
}
int so_gach_ngang(int x,int y){
    int s=0;
    // Tìm số gạch ngang của giờ
    if (x < 10){
        s += n[x];
    } else {
        s += n[x % 10] + n[x / 10];
    }
    // Tìm số gạch ngang của phút
    if (y < 10){
        s += n[0] + n[y];
    } else {
        s += n[y % 10] + n[y / 10];
    }
    return s;
}
int xuat(int x, int y){
    cout << x << ":";
        if (y < 10){
            cout << '0' << y;
        }
}
int main(){
    int n,v,h;
    bool check = 0;
    cin >> v >> h;
    for (int i = 0; i<=23; i++){
        for (int j = 0; j<=59; j++){
            check = so_gach_dung(i,j) == v && so_gach_ngang(i,j) == h;
            if (check){
                xuat(i,j);
                break;
            }
        }
        if (check) break;
    }
}
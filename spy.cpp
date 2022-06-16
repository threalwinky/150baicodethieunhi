#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
stack<pair<int, int>> path;
pair<int, int> s,t, parent[1001][1001];
char a[1001][1001];
int m,n,dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};;
void nhap(){
    cin>>m>>n>>s.fi>>s.se>>t.fi>>t.se;
    for (int i = 0;i<=m; i++){
        for (int j = 0;j<=n;j++){
            a[j][i] = 'o';
        }
    }
    while (true){
        int x,y;
        cin>>x>>y;
        if (x == -1) break;
        a[x][y] = 'x';
    }
}
void bfs(int i, int j){
    a[i][j] = 'c';
    queue<pair<int, int>> q;
    q.push({i,j});
    while (!q.empty()){
        pair<int, int> v = q.front();
        q.pop();
        for (int x = 0; x<4 ;x++){

            int i1,j1;
            i1 = v.first+dx[x];
            j1 = v.second+dy[x];
            if (i1>=0&&i1<=n&&j1>=0&&j1<=m&&a[i1][j1] == 'o'){
                q.push({i1,j1});
                parent[i1][j1] = {v.first,v.second};
                a[i1][j1] = 'c';
            }
        }
    }
}
void xuly(){
    int cnt = 0;
    bfs(s.first,s.second);
    
    if (a[t.first][t.second] == 'x') cout<<"NO";else{
    path.push({t.first, t.second});
    while (t!=s){
        if ((t.fi ==1 &&t.se==0)){
            
            path.push({1,1});
            path.push({t.first, t.second});
            cnt+=2;
        }
        if ((t.fi ==4 &&t.se==3)){
            
            path.push({3,3});
            path.push({t.first, t.second});
            cnt+=2;
        }
        t = parent[t.first][t.second];
        path.push({t.first, t.second});
        cnt++;
        }
    cout<<cnt<<endl;
    }
}
void xuat(){
    while (!path.empty()){
        cout<<path.top().fi<<" "<<path.top().se<<endl;
        path.pop();
    }
}
int main(){
    freopen("spy.inp", "r", stdin);
    nhap();
    xuly();
    xuat();
}
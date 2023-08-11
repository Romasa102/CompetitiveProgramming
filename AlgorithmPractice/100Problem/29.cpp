#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll R,C;
    cin >> R >> C;
    ll sy,sx;
    cin >> sy >> sx;
    ll gy,gx;
    cin >> gy >> gx;
    sy--;sx--;gy--;gx--;
    ll maps[50][50];
    rep(i,R){
        rep(j,C){
            char c;
            cin >> c;
            if(c == '#')maps[i][j] = -1;
            else maps[i][j] = 0;
        }
    }
    queue<P> Q;
    Q.push(P(sx,sy));
    maps[sy][sx] = 1;
    while(Q.size()){
        ll x = Q.front().first;
        ll y = Q.front().second;
        Q.pop();
        if(x+1<C && maps[y][x+1] == 0){
            maps[y][x+1] = maps[y][x] + 1;
            Q.push(P(x+1,y));
        }
        if(x-1>=0 && maps[y][x-1] == 0){
            maps[y][x-1] = maps[y][x] + 1;
            Q.push(P(x-1,y));
        }
        if(y+1<R && maps[y+1][x] == 0){
            maps[y+1][x] = maps[y][x] + 1;
            Q.push(P(x,y+1));
        }
        if(y-1>=0 && maps[y-1][x] == 0){
            maps[y-1][x] = maps[y][x] + 1;
            Q.push(P(x,y-1));
        }
    }
    cout << maps[gy][gx] - 1 << endl;
}
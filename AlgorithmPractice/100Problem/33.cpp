#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll h,w;
    cin >> h >> w;
    string s[h];
    rep(i,h){
        cin >> s[i];
    }
    ll WhiteC = 0;
    queue<P> Q;
    ll dis[h][w];
    rep(i,h){
        rep(j,w){
            dis[i][j] = -1;
            if(s[i][j] == '.')WhiteC++;
        }
    }
    Q.push({0,0});
    dis[0][0] = 1;
    while(Q.size()){
        ll x = Q.front().first;
        ll y = Q.front().second;
        if(x+1 < w && s[y][x+1] == '.' && dis[y][x+1] == -1){
            dis[y][x+1] = dis[y][x] + 1;
            Q.push({x+1,y});
        }
        if(y+1 < h && s[y+1][x] == '.' && dis[y+1][x] == -1){
            dis[y+1][x] = dis[y][x] + 1;
            Q.push({x,y+1});
        }
        if(x-1 >= 0 && s[y][x-1] == '.' && dis[y][x-1] == -1){
            dis[y][x-1] = dis[y][x] + 1;
            Q.push({x-1,y});
        }
        if(y-1 >= 0 && s[y-1][x] == '.' && dis[y-1][x] == -1){
            dis[y-1][x] = dis[y][x] + 1;
            Q.push({x,y-1});
        }
        Q.pop();
    }
    if(dis[h-1][w-1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << WhiteC - dis[h-1][w-1] << endl;
}
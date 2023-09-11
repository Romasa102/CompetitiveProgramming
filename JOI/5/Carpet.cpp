#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    bool maps[H][W];
    bool searched[H][W];
    ll len[H][W];
    rep(i,H){
        rep(j,W){
            len[i][j] = 100000000;
            searched[i][j] = false;
            if(S[i][j] == '#'){
                maps[i][j] = true;
            }else{
                maps[i][j] = false;
            }
        }
    }
    queue<P> Q;
    P uldr[4] = {{0,1},{1,0},{-1,0},{0,-1}};
    Q.push({0,0});
    len[0][0] = 0;
    while(!Q.empty()){
        P current = Q.front();
        Q.pop();
        if(searched[current.first][current.second]){
            continue;
        }searched[current.first][current.second] = true;
        rep(i,4){
            ll x = current.first + uldr[i].first;
            ll y = current.second + uldr[i].second;
            if(x >= H || y >= W || x < 0 || y < 0){
                continue;
            }
            if(maps[x][y] != maps[current.first][current.second]){
                len[x][y] = min(len[x][y], len[current.first][current.second] + 1);
                if(!searched[x][y]){
                    Q.push({x,y});
                }
            }
        }
    }
    if(len[H-1][W-1] == 100000000){
        cout << -1 << endl;
        return 0;
    }
    cout << len[H-1][W-1] << endl;
}
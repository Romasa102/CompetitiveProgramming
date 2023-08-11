#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    string map[H];
    P startPoint;
    P findPoint[N];
    rep(i,H){
        cin >> map[i];
    }

    rep(i,H){
        rep(j,W){
            if(map[i][j] == 'S'){
                startPoint = {i,j};
                map[i][j] = '.';
            }
            if(map[i][j] != 'S' && map[i][j] != '.' && map[i][j] != 'X') {
                findPoint[map[i][j] - '1'] = {i,j};
                map[i][j] = '.';
            }
        }
    }
    queue<P> Q;
    Q.push(startPoint);
    ll counter[H][W];
    ll ans = 0;
    rep(i,N){
        rep(j,H){
            rep(k,W){
                counter[j][k] = -1;
            }
        }
        if(i != 0) Q.push(findPoint[i-1]);
        counter[Q.front().first][Q.front().second] = 0;
        while(Q.size()){
            ll x = Q.front().first;
            ll y = Q.front().second;
            if(x-1>=0 && map[x-1][y] == '.' && counter[x-1][y] == -1){
                Q.push({x-1,y});
                counter[x-1][y] = counter[x][y]+1;
            }
            if(x+1<H && map[x+1][y] == '.' && counter[x+1][y] == -1){
                Q.push({x+1,y});
                counter[x+1][y] = counter[x][y]+1;
            }
            if(y-1>=0 && map[x][y-1] == '.' && counter[x][y-1] == -1){
                Q.push({x,y-1});
                counter[x][y-1] = counter[x][y]+1;
            }
            if(y+1<W && map[x][y+1] == '.' && counter[x][y+1] == -1){
                Q.push({x,y+1});
                counter[x][y+1] = counter[x][y]+1;
            }
            Q.pop();
        }
        ans+=counter[findPoint[i].first][findPoint[i].second];
    }
    cout << ans << endl;
}
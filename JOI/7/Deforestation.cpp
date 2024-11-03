#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll S[H][W];
    rep(i,H)rep(j,W) cin >> S[i][j];
    ll dp[H][W][H*W];
    ll visited[H][W][H*W];
    rep(i,H) rep(j,W) rep(k,H*W) dp[i][j][k] = 1LL<<60;
    rep(i,H) rep(j,W) rep(k,H*W) visited[i][j][k] = 0;
    queue<pair<P,ll>> Q;//(x,y,depth)
    ll dx[4] = {1,0,-1,0};
    ll dy[4] = {0,1,0,-1};
    Q.push({{0,0},0});
    dp[0][0][0]=0;
    while(!Q.empty()){
        auto cur = Q.front();Q.pop();
        //if(visited[cur.first.first][cur.first.second][cur.second]) continue;
        //visited[cur.first.first][cur.first.second][cur.second] = 1;
        ll dist = cur.second;
        if(dist > H*W)continue;
        rep(i,4){
            ll nx = cur.first.first + dx[i];
            ll ny = cur.first.second + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            dp[nx][ny][dist+1] = min(dp[nx][ny][dist+1],dp[cur.first.first][cur.first.second][dist] + (1+2*dist) * S[nx][ny]);
            if(visited[nx][ny][dist+1]) continue;
            visited[nx][ny][dist+1] = 1;
            Q.push(make_pair(make_pair(nx,ny),dist+1));
        }
    }
    ll ans= 1LL<<60;
    rep(i,H*W){
        ans = min(dp[H-1][W-1][i],ans);
    }
    cout << ans << endl;
}
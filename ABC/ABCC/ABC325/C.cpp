#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool found[2000][2000];
bool graph[2000][2000];
int dx[] = { 1,0,-1,0,1,1,-1,-1 }; int dy[] = { 0,1,0,-1,1,-1,1,-1 };
ll H,W;
bool dfs(ll x,ll y){
    if(found[x][y])return false;
    found[x][y]=true;
    if(!graph[x][y])return false;
    rep(d,8){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx && nx < H && 0 <= ny && ny < W && graph[nx][ny] && !found[nx][ny]) {
            dfs(nx,ny);
        }
    }
    return true;
}
int main(){
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    rep(i,H){
        rep(j,W){
            found[i][j]=false;
            if(S[i][j] == '.'){
                graph[i][j] = false;
            }else{
                graph[i][j] =true;
            }
        }
    }
    ll ans =0;
    rep(i,H){
        rep(j,W){
            if(dfs(i,j)){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    string S[N];
    rep(i,N)cin >> S[i];
    P initialA;
    P initialB;
    bool aDone = false;
    rep(i,N){
        rep(j,N){
            if(S[i][j] == 'P'){
                if(aDone){
                    initialB.first = i;
                    initialB.second = j;
                }else{
                    aDone = true;
                    initialA.first = i;
                    initialA.second = j;
                }
            }
        }
    }
    queue<pair<pair<P,P>,ll>> Q;
    Q.push({{initialA,initialB},0});
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    bool visited[N][N][N][N];
    rep(i,N)rep(j,N)rep(k,N)rep(l,N)visited[i][j][k][l] = false;
    ll ans = 1e9;
    while(!Q.empty()){
        auto cur = Q.front().first;
        Q.pop();
        P a = cur.first;P b = cur.second;
        if(visited[a.first][a.second][b.first][b.second])continue;
        visited[a.first][a.second][b.first][b.second] = true;
        if(a == b){
            ans = min(ans,Q.front().second);
            return 0;
        }
        rep(i,4){
            if(a.first + dx[i] < 0 || a.first + dx[i] >= N || a.second + dy[i] < 0 || a.second + dy[i] >= N)continue;
            if(b.first + dx[i] < 0 || b.first + dx[i] >= N || b.second + dy[i] < 0 || b.second + dy[i] >= N)continue;
            if(S[b.first + dx[i]][b.second + dy[i]] == '#' && S[a.first + dx[i]][a.second + dy[i]] == '#')continue;
            else if(S[a.first + dx[i]][a.second + dy[i]] == '#')b.first+=dx[i],b.second+=dy[i];
            else if(S[b.first + dx[i]][b.second + dy[i]] == '#')a.first+=dx[i],a.second+=dy[i];
            else a.first+=dx[i],a.second+=dy[i],b.first+=dx[i],b.second+=dy[i];
            if(visited[a.first][a.second][b.first][b.second])continue;
            Q.push({{a,b},Q.front().second+1});
        }
    }
    if(ans == 1e9)cout << -1 << endl;
    else cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll dx[8] = {-1,0,1,1,1,0,-1,-1};
    ll dy[8] = {-1,-1,-1,0,1,1,1,0};
    ll H,W;cin >> H >> W;
    string S[H];rep(i,H)cin >> S[i];
    vector<vector<ll>> surrounding(H,vector<ll>(W,0));
    rep(i,H){
        rep(j,W){
            rep(k,8){
                if(i + dx[k] < 0 || i + dx[k] >= H || j + dy[k] < 0 || j + dy[k] >= W)continue;
                if(S[i+dx[k]][j+dy[k]] == '.')surrounding[i][j]++;
            }
        }
    }
    vector<vector<bool>>visited(H,vector<bool>(W,false));
    queue<P> visit;
    rep(i,H)rep(j,W){
        if(S[i][j] == '.'){
            visited[i][j]=true;
            continue;
        }
        if(S[i][j] - '0' <= surrounding[i][j]){
            visited[i][j]=true;
            visit.push({i,j});
        }
    }
    ll waveC = visit.size();
    ll nextW = 0;
    ll ans = 0;
    while(!visit.empty()){
        auto cur = visit.front();visit.pop();
        waveC--;
        rep(i,8){
            if(cur.first + dx[i] < 0 || cur.first + dx[i] >= H || cur.second + dy[i] < 0 || cur.second + dy[i] >= W)continue;
            surrounding[cur.first+dx[i]][cur.second+dy[i]]++;
            if(visited[cur.first+dx[i]][cur.second+dy[i]])continue;
            if(surrounding[cur.first+dx[i]][cur.second+dy[i]] >= S[cur.first+dx[i]][cur.second+dy[i]]-'0'){
                nextW++;
                visited[cur.first+dx[i]][cur.second+dy[i]]=true;
                visit.push({cur.first+dx[i],cur.second+dy[i]});
            }
        }
        if(waveC==0){
            waveC = nextW;
            nextW = 0;
            ans++;
        }
    }
    cout << ans << endl;
}
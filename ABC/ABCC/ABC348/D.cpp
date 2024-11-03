#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string A[H];
    rep(i,H)cin >> A[i];
    P start = {0,0};
    P end = {0,0};
    rep(i,H){
        rep(j,W){
            if(A[i][j] == 'S'){
                start = {i,j};
            }else if(A[i][j] == 'T'){
                end = {i,j};
            }
        }
    }
    ll N;
    cin >> N;
    ll R[N+1],C[N+1],E[N+1];
    map<P,ll> potion;
    ll StartMed = -1;
    rep(i,N+1) {
        if(i == N){
            R[N] = end.first;C[N] = end.second;E[N] = 0;
        }else{
            cin >> R[i] >> C[i] >> E[i];
            R[i]--;
            C[i]--;E[i]++;
            if(R[i] == start.first && C[i] == start.second){
                StartMed = i;
            }
        }
        potion[{R[i], C[i]}] = i;
    }
    if(StartMed == -1){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<ll>> mp(N+1);

    ll counter = 0;
    rep(i,N+1){
        queue<pair<P,ll>> q;
        ll dx[4] = {0,0,1,-1};
        ll dy[4] = {1,-1,0,0};
        vector<vector<bool>> visited(H,vector<bool>(W,false));
        rep(o,H)rep(j,W)visited[o][j] = false;
        q.push({{R[i],C[i]},E[i]});
        while(!q.empty()){
            auto cur = q.front();q.pop();
            if(visited[cur.first.first][cur.first.second])continue;
            ll energy = cur.second;energy--;
            visited[cur.first.first][cur.first.second] = true;
            if(potion.find(cur.first) != potion.end() && i != potion[cur.first]){
                mp[i].push_back(potion[cur.first]);
                mp[potion[cur.first]].push_back(i);
            }
            if(energy<0)break;
            rep(l,4){
                if(cur.first.first+dx[l] < H && 0 <= cur.first.first+dx[l] && cur.first.second+dy[l] < W  && 0<= cur.first.second+dy[l]
                   &&A[cur.first.first+dx[l]][cur.first.second+dy[l]] != '#' && !visited[cur.first.first+dx[l]][cur.first.second+dy[l]]){
                    //cout << cur.first.first+dx[l] << " " << cur.first.second+dy[l] << " " << H << " " << W << (cur.first.second+dy[l] < H) << endl;
                    q.push({{cur.first.first+dx[l],cur.first.second+dy[l]},energy});
                }
            }
        }
    }
    vector<ll> visited(N+1,false);
    queue<ll> q;
    q.push(StartMed);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        if(visited[cur])continue;
        visited[cur]= true;
        rep(i,mp[cur].size()){
            if(!visited[mp[cur][i]]){
                q.push(mp[cur][i]);
            }
        }
    }
    if(visited[N] == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    ll N,K;cin>>N>>K;
    string S[N];rep(i,N)cin >> S[i];
    vector<deque<ll>> grid(10,deque<ll>(N));
    rep(i,N){
        rep(j,10){
            grid[j][N-1-i]=(S[i][j]-'0');
        }
    }
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    while(true){
        vector<vector<bool>> visited(10,vector<bool>(N,false));
        queue<P> Q;
        bool CONT = false;
        rep(i,10){
            rep(j,grid[i].size()){
                if(visited[i][j])continue;
                if(grid[i][j] == 0)continue;
                Q.push({i,j});
                vector<P> passed;
                while(!Q.empty()){
                    P cur = Q.front();Q.pop();
                    if(visited[cur.first][cur.second])continue;
                    visited[cur.first][cur.second]=true;
                    passed.push_back(cur);
                    rep(k,4){
                        if(cur.first+dx[k] < 0 || cur.second + dy[k] < 0 || cur.first + dx[k] >= 10 || cur.second + dy[k] >= grid[cur.first].size()){
                            continue;
                        }
                        if(visited[cur.first+dx[k]][cur.second+dy[k]])continue;
                        if(grid[cur.first][cur.second] == grid[cur.first+dx[k]][cur.second + dy[k]]){
                            Q.push({cur.first+dx[k],cur.second+dy[k]});
                        }
                    }
                }
                if(passed.size()>=K){
                    CONT = true;
                    rep(k,passed.size()){
                        grid[passed[k].first][passed[k].second]=0;
                    }
                }
            }
        }
        rep(i,10){
            while(!grid[i].empty() && grid[i].front()==0)grid[i].pop_front();
        }
        if(!CONT)break;
    }
    rep(i,10){
        grid[i].resize(N,0);
    }
    rep(i,N){
        rep(j,10){
            cout << grid[j][N-1-i];
        }cout << endl;
    }
}
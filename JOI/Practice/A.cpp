#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    ll dp[H][W];
    bool visited[H][W];//y,x
    rep(i,H)rep(j,W){
            dp[i][j]=1LL<<60;
            visited[i][j]=false;
        }
    ll dx[4]={1,-1,0,0};
    ll dy[4]={0,0,1,-1};
    bool visiteds[H][W];//y,x
    rep(i,H)rep(j,W){
            visiteds[i][j]=false;
        }
    priority_queue<pair<ll,pair<ll,P>>,vector<pair<ll,pair<ll,P>>>,greater<pair<ll,pair<ll,P>>>> Qs;
    Qs.push({0,{0,{0,0}}});
    dp[0][0] = 0;
    while(!Qs.empty()){
        auto cur = Qs.top();Qs.pop();
        ll cost = cur.first;
        ll time = cur.second.first;
        P pos = cur.second.second;
        if(visiteds[pos.first][pos.second])continue;
        visiteds[pos.first][pos.second]=true;
        rep(i,4){
            if(pos.first+dy[i]>=H||pos.first+dy[i]<0)continue;
            if(pos.second+dx[i]>=W||pos.second+dx[i]<0)continue;
            if(visiteds[pos.first+dy[i]][pos.second+dx[i]])continue;
            dp[pos.first+dy[i]][pos.second+dx[i]]=min(cost+ A[pos.first+dy[i]][pos.second+dx[i]] * (time*2+1),dp[pos.first+dy[i]][pos.second+dx[i]]);
            Qs.push({dp[pos.first+dy[i]][pos.second+dx[i]],{time+1,{pos.first+dy[i],pos.second+dx[i]}}});
        }
    }
    queue<pair<ll,pair<ll,P>>> Q;
    Q.push({0,{0,{0,0}}});
    dp[0][0] = 0;
    while(!Q.empty()){
        auto cur = Q.front();Q.pop();
        ll cost = cur.first;
        ll time = cur.second.first;
        P pos = cur.second.second;
        if(visited[pos.first][pos.second])continue;
        visited[pos.first][pos.second]=true;
        rep(i,4){
            if(pos.first+dy[i]>=H||pos.first+dy[i]<0)continue;
            if(pos.second+dx[i]>=W||pos.second+dx[i]<0)continue;
            if(visited[pos.first+dy[i]][pos.second+dx[i]])continue;
            dp[pos.first+dy[i]][pos.second+dx[i]]=min(cost+ A[pos.first+dy[i]][pos.second+dx[i]] * (time*2+1),dp[pos.first+dy[i]][pos.second+dx[i]]);
            Q.push({dp[pos.first+dy[i]][pos.second+dx[i]],{time+1,{pos.first+dy[i],pos.second+dx[i]}}});
        }
    }
    cout << dp[H-1][W-1] << endl;
}
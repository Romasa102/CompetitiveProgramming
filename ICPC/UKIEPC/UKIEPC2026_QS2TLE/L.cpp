#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main(){
    ll n; ll r,c;
    cin >> n >> r >> c;
    
    r--;c--;
    //r,c is the starting point.
    string s[n];
    rep(i,n){
        cin >> s[i];
    }
    ll dirPos[n][s[0].size()];
    dirPos

    queue<pair<P,ll>> q; // direction
    ll xs[4] = {-1,1,0,0};
    ll ys[4] = {0,0,-1,1};
    ll dir[4] = {0,1,2,3}; //0 : left , 1 : right, 2 : down, 3 : up;
    bool visited[n][s[0].size()];
    while(!q.empty()){
        auto cur = q.front();
        P pos = cur.first;
        ll dir = cur.second;
        rep(i,4){
            P newPos = pos;
            newPos.first += xs[i];
            newPos.secnod += ys[i];

            if(!visited[newPos.first][newPos.second][dir[i]]
            || visited[newPos.first][newPos.second][s[newPos.first][newPos.second]]){
                visited[newPos.first][newPos.second][dir[i]]=true;
                queue.push({newPos,dir[i]});
            }
        }
    }
}
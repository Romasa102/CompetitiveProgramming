#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<double,double>;
int main(){
    ll n,m,d,k;//num of city , flu end time, flu infection area, time we want
    cin >> n >> m >> d >> k;
    P xy[n];
    map<P,ll> pos;
    rep(i,n){
        cin >> xy[i].first >> xy[i].second;
        pos[{xy[i].first,xy[i].second}]=i;
    }
    vector<ll> startT(n,-5000);
    vector<bool> visited(n,false);
    map<ll,vector<ll>> connection;
    queue<pair<ll,ll>> Q;
    Q.push({0,0});
    while(!Q.empty()){
        pair<ll,ll> cur = Q.front();Q.pop();
        if(visited[cur.first])continue;
        if(cur.second>k)continue;
        visited[cur.first]=true;startT[cur.first]=cur.second;
        repp(i,max(xy[cur.first].first-d,(double)0),xy[cur.first].first+d+1){
            repp(j,max((double)0,xy[cur.first].second-d),xy[cur.first].second+d+1){
                if(sqrt((double)((i-xy[cur.first].first)*(i-xy[cur.first].first)+(j-xy[cur.first].second)*(j-xy[cur.first].second)))>d)continue;
                if(pos.find({i,j})==pos.end())continue;
                if(visited[pos[{i,j}]])continue;
                Q.push({pos[{i,j}],cur.second+1});
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        if(startT[i]+m>k && startT[i]<=k){
            ans ++;
        }
    }
    cout << ans << endl;
}
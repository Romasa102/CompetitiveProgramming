#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,Y;
    cin >> N >> M >> Y;
    map<ll,vector<P>> mp;
    vector<ll> dist(N,-1);
    rep(i,M){
        ll u,v,t;
        cin >> u >> v >> t;
        mp[u-1].push_back({v-1,t});
        mp[v-1].push_back({u-1,t});
    }
    P X[N];
    rep(i,N){
        cin >> X[i].first;
        X[i].second = i;
    }
    priority_queue<P> pq;//weight, dest;
    pq.push({0,0});
    while(!pq.empty()){
        P cur = pq.top();pq.pop();
        ll curDist = cur.first;
        dist[cur.second] = curDist;

        for(auto i : mp[cur.second]){
            if(dist[i.second]==-1){
                pq.push({i.second + curDist,i.first});
            }
        }
        rep(i,N){
            if(dist[i]==-1){
                pq.push({X[i].first + X[cur.second].first + Y,i});
            }
        }
    }
    rep(i,N){
        cout << dist[i] << " ";
    }cout << endl;
}
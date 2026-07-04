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
    vector<ll> dist(1000002,1LL<<50);
    rep(i,M){
        ll u,v,t;
        cin >>  u >> v >> t;
        u--;v--;
        mp[u].push_back({v,t});
        mp[v].push_back({u,t});
    }
    ll X[N];
    rep(i,N)cin >> X[i];
    mp[1000000].push_back({1000001,Y});
    rep(i,N){
        mp[i].push_back({1000000,X[i]});
        mp[1000001].push_back({i,X[i]});
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,0}); //cost,dest
    dist[0] = 0;
    while(!pq.empty()){
        P cur = pq.top();pq.pop();
        ll curC = cur.first;
        ll curI = cur.second;
        if(curC > dist[curI])continue;
        for(auto i : mp[curI]){
            if(dist[i.first]<curC+i.second)continue;
            dist[i.first] = curC + i.second;
            pq.push({curC + i.second, i.first});
        }
    }
    repp(i,1,N){
        cout << dist[i] << " ";
    }cout << endl;
}
//yummy
//wanya chan tensai
//nom
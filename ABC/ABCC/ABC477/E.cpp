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
    ll N,Q;
    cin >> N >> Q;
    ll A[N],B[N];
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    map<ll,vector<P>> mp;
    rep(i,N){
        ll j = (i+1)%N;
        mp[i].push_back({j,A[i]});
        mp[j].push_back({i,A[i]});
        mp[N].push_back({i,B[i]});
        mp[i].push_back({N,B[i]});
    }
    const ll INF = 1LL<<50;
    vector<ll> dist(N+1,INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    dist[N] = 0;
    pq.push({0,N});
    while(!pq.empty()){
        auto [d,v] = pq.top();pq.pop();
        if(d > dist[v])continue;
        for(auto [to,w] : mp[v]){
            if(dist[to] > d+w){
                dist[to] = d+w;
                pq.push({dist[to],to});
            }
        }
    }
    vector<ll> sum(N+1,0);
    rep(j,N)sum[j+1] = sum[j]+A[j];

    rep(i,Q){
        ll S,T;
        cin >> S >> T;S--;T--;
        //so the minimum path is either through N+1 or by going around the circle which have 2 ways.
        // so we can just compare 3 ways.
        //actually ther is a case where it is closer to go through other node and then to N+1
        //we can calculate minimum distance from N+1 to all the node once and compute.
        //T can be N+1 (the center itself): only the path through the center makes sense
        if(T == N){
            cout << dist[S] << '\n';
            continue;
        }
        ll fst = dist[S]+dist[T];
        ll snd = sum[max(S,T)]-sum[min(S,T)];
        ll trd = (sum[N]-sum[max(S,T)]) + sum[min(S,T)];
        cout << min(trd,min(fst,snd)) << endl;
    }
}
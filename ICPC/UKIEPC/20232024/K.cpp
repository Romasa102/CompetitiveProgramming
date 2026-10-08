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
vector<ll> par;
ll find(ll x){
    if(par[x] != x){
        return find(par[x]);
    }
    return x;
}
void unite(ll x, ll y){
    par[x] = find(y);
}
int main(){
    ll n,m;
    cin >> n >> m;
    ll a[m],b[m];
    map<P,ll> edges;
    rep(i,m){
        cin >> a[i] >> b[i];
        edges[{a[i],b[i]}]++;
    }
    vector<pair<ll,P>> edgeSorted;
    for(auto edge : edges){
        edgeSorted.push_back({edge.second,edge.first});
    }
    sort(edgeSorted.begin(),edgeSorted.end(),greater<pair<ll,P>>());
    rep(i,n)par[i]=i;
    for(auto edgePair : edgeSorted){
        auto edge = edgePair.second;
        if(par[edge.second] != par[edge.first]){
            par[]
        }
    }
}
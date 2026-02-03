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
vector<ll> parents;
ll root(ll x){
    if(parents[x]==x)return x;
    return root(parents[x]);
}
void dsuU(ll x,ll y){
    parents[x]=root(y);
}
int main(){
    ll N;cin>>N;
    ll P[N];
    rep(i,N){
        cin>>P[i];P[i]--;
    }
    parents.resize(N);
    rep(i,N)parents[i]=i;
    rep(i,N){
        dsuU(P[i],i);
    }
    map<ll,ll> mp;
    rep(i,N){
        mp[root(i)]++;
    }
    ll ans = 0;
    for(auto it : mp){
        ans +=(it.second*(it.second-1))/2;
    }
    cout << ans << endl;
}
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
map<ll,vector<ll>> mp;
vector<ll> num;
vector<bool> visited;
vector<ll> que;
void update(ll p = 0,ll x = 0){
    visited[p]=true;
    ll nxt = x+que[p];
    num[p]+=nxt;
    rep(i,mp[p].size()){
        if(visited[mp[p][i]])continue;
        update(mp[p][i],nxt);
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    num.resize(N,0);
    que.resize(N,0);
    visited.resize(N,false);
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        mp[a-1].push_back(b-1);
        mp[b-1].push_back(a-1);
    }
    rep(_,Q){
        ll p,x;
        cin >> p >> x;
        que[p-1]+=x;
    }
    update(0,0);
    rep(i,N)cout << num[i] << " ";
    cout << endl;
}
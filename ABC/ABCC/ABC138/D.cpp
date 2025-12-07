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
map<ll,vector<ll>> edge;
vector<bool> visited;
vector<ll> ans;
vector<ll> queNum;
void dfs(ll val, ll pos){
    visited[pos] = true;
    ll cur = val + queNum[pos];
    ans[pos] = cur;
    rep(i,edge[pos].size()){
        if(visited[edge[pos][i]]){
            continue;
        }
        dfs(cur,edge[pos][i]);
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N-1],b[N-1];
    ll p[Q],x[Q];
    visited.resize(N);
    ans.resize(N);
    queNum.resize(N);
    rep(i,N)queNum[i] = 0;
    rep(i,N-1){
        cin >> a[i] >> b[i];
        edge[a[i]-1].push_back(b[i]-1);
        edge[b[i]-1].push_back(a[i]-1);
    }
    rep(i,Q){
        cin >> p[i] >> x[i];
        queNum[p[i]-1]+=x[i];
    }
    dfs(0,0);
    rep(i,N){
        cout << ans[i] << " ";
    }cout << endl;
}

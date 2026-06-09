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
vector<ll> parent;
ll find(ll x){
    if(parent[x]==x)return x;
    return parent[x] = find(parent[x]);
}
void unions(ll a,ll b){
    parent[a]=b;
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    parent.resize(N);
    rep(i,N)parent[i]=i;
    rep(_,Q){
        ll C,Q;
        cin >> C >> Q;
        unions(C-1,Q-1);
    }
    vector<ll> ans(N);
    rep(i,N){
        ans[find(i)]++;
    }
    rep(i,N){
        cout << ans[i] << " ";
    }cout << endl;
}
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
vector<ll> paren;

int parent(ll x){
    if(x == paren[x]) return x;
    return paren[x] = parent(paren[x]);
}
void merge(ll a,ll b){
    paren[parent(a)] = parent(b);
}

ll mod_pow(ll p, ll mod = 998244353){     
    ll res = 1;
    ll pw = 2;
    while(p > 0){
        if(p & 1){
            res = res * pw % mod;
        }
        pw = pw * pw % mod;
        p >>= 1;
    }
    return res;
}
int main(){
    ll N,M;
    cin >> N >> M;
    paren.resize(N);
    rep(i,N)paren[i]=i;
    ll U[M],V[M];
    rep(i,M){
        cin >> U[i] >> V[i];
        U[i]--;V[i]--;
    }
    ll curC = N;
    ll ans = 0;
    for(ll i = M-1; i >= 0; i--){
        ll pu = parent(U[i]);
        ll pv = parent(V[i]);
        if(pu == pv){

        }else if(curC == 2){
            ans += mod_pow(i+1);
            ans %= 998244353;
        }else{
            curC--;
            merge(U[i],V[i]);
        }
    }
    cout << ans << endl;
}
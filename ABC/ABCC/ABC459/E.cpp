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
vector<ll> Par,C,D;
map<ll,vector<ll>> child;
bool failed = false;
ll ans = 1;
const ll MOD = 998244353;
const ll MAXN = 2e6 + 5;
ll fact[MAXN], inv_fact[MAXN];

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll getC(ll N, ll R) {
    if (R < 0 || R > N) return 0;
    if (R > N - R) R = N - R;
    ll result = 1;
    rep(i, R) {
        result = result % MOD * ((N - i) % MOD) % MOD;
        result = result % MOD * power(i + 1, MOD - 2, MOD) % MOD;
    }
    return result;
}
P dfs(ll x){
    ll childTasked = 0;
    ll childCandyTotal = 0;
    for(ll i : child[x]){
        //cout << i << " is child of " << x << endl;
        auto childR =dfs(i);
        childTasked+=childR.first;
        childCandyTotal+=childR.second;
    }
    if(childCandyTotal + C[x] - childTasked - D[x] < 0)failed = true;
    //cout << "Currently at " << x << " total candy available here is " << childCandyTotal + C[x] - childTasked << " total candy needed is " << D[x] << endl;
    ans = ans * getC(childCandyTotal + C[x] - childTasked, D[x]) % MOD;
    return {childTasked + D[x] , childCandyTotal + C[x]};
}
int main(){
    ll N;
    cin >> N;
    Par.resize(N+2);
    C.resize(N+1);
    D.resize(N+1);
    repp(i,2,N+1)cin >> Par[i];
    repp(i,1,N+1)cin >> C[i];
    repp(i,1,N+1)cin >> D[i];
    repp(i,2,N+1){
        child[Par[i]].push_back(i);
    }
    dfs(1);
    if(failed){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}
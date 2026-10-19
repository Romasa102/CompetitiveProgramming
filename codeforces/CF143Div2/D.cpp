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
const ll mod = 998244353;//10^9
const ll LIM = 3000000; ///include-line

int main(){

    ll* inv = new ll[LIM] - 1; 
    inv[1] = 1;
    repp(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    ll n;
    cin >> n;
    ll w[n];
    rep(i,n)cin >> w[i];
    ll base = 1;
    
    rep(i,n/6){
        base *= (n/3-i);
        base %= mod;
    }
    rep(i,n/6){
        base *= inv[(i+1)];
        base %= mod;
    }
    ll cur = 0;
    rep(_,n/3){
        vector<ll> tri;
        rep(i,3){
            tri.push_back(w[cur]);
            cur++; 
        }
        sort(tri.begin(),tri.end());
        if(tri[0]==tri[1] && tri[1]==tri[2]){
            base *= 3;
            base %= mod; 
        }else if(tri[0]==tri[1]){
            base *= 2;
            base %= mod;
        }
    }
    cout << base << endl;
}
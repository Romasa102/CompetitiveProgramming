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


vector<P> prime_factorize(ll N) {
    vector<P> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n,x;
        cin >> n >> x;
        ll a[n];
        rep(i,n)cin >> a[i];
        map<ll,ll> prims;
        ll ans = 1;
        rep(i,n){
            vector<P> primes = prime_factorize(a[i]);
            rep(j,primes.size()){
                //cout << primes[j].first << "  :  "  << primes[j].second << endl;;
                prims[primes[j].first] += primes[j].second;
                prims[primes[j].first] %= 1000000007;
            }
        }
        for(auto i : prims){
            ans *= (i.second + 1);
            ans %= 1000000007;
        }
        cout << ans % 1000000007 << endl;
    }
}
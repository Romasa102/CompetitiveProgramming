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
vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= N; ++p) {
        if (N % p != 0) {
            continue;
        }
        int e = 0;
        while (N % p == 0) {
            ++e;

            N /= p;
        }
        res.emplace_back(p, e);
    }
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n,k;
        cin >> n >> k;
        ll a[n];
        rep(i,n){
            cin >> a[i];
        }
        ll ans = 0;
        rep(i,n){
            ll temp;
            if(a[i]%k==0){
                temp = a[i]/k;
            }else{
                temp = a[i]/k;
                temp++;
            }
            ll num = 0;
            repp(j,temp,(ll)sqrt(a[i])){
                if(a[i]%j==0){
                    num = j;
                }
            }
            cout << num << " ";
            const auto& pf = prime_factorize(num);
            ll cur = 1;
            for(auto [p,e] : pf){
                rep(_,e){
                    ans += cur;
                    cur *= p;
                }
            }
        }
        cout << ans << endl;
    }
}
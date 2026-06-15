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

ll bigC(ll n, ll k) {
    if (k > n) {
        return 0;
    }
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main(){
    ll N,D;
    cin >> N >> D;
    ll S[N],T[N];
    vector<ll> cumS(1100000,0);
    rep(i,N){
        cin >> S[i] >> T[i];
        T[i] -= D;
        if(S[i] <= T[i]){
            cumS[S[i]]++;
            cumS[T[i]+1]--;
        }
    }
    ll cur = 0;
    ll ans = 0;
    rep(i,1010000){
        cur+=cumS[i];
        ans += bigC(cur,2);
    }cout << endl;
    cout << ans << endl;
}
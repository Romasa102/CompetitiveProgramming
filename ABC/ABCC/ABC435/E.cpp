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
int main(){
    ll N,Q;cin >> N >> Q;
    set<P> ranges;
    ranges.insert({0,0});
    ll ans = N;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        auto it = ranges.lower_bound({L, -1e18});
        if (it != ranges.begin()) {
            it--;
            if (it->second < L) {
                it++;
            }
        }

        while (it != ranges.end()) {
            ll cur_L = it->first;
            ll cur_R = it->second;

            if (cur_L <= R && cur_R >= L) {
                ans += (cur_R - cur_L + 1);
                L = min(L, cur_L);
                R = max(R, cur_R);
                it = ranges.erase(it);
            } else {
                if (cur_L > R) break;
                it++;
            }
        }
        ranges.insert({L, R});
        ans -= (R - L + 1);

        cout << ans << endl;
    }
}
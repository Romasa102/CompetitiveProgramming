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
    ll t;
    cin >> t;
    
    rep(_,t){
        ll n;
        cin >> n;
        ll h[n];
        ll maxH = 0;
        ll minH = 1LL<<40;
        rep(i,n){
            cin >> h[i];
            minH = min(minH,h[i]);
            maxH = max(maxH,h[i]);
        }
        cout << maxH - minH + 1 << endl;;
    }
}
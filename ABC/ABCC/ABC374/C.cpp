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
    ll N;
    cin >> N;
    ll K[N];
    rep(i,N)cin >> K[i];
    ll ans = 1LL<<60;
    ll sum = 0;
    rep(i,N)sum+=K[i];
    for(ll bit = 0;bit < (1<<N);bit++){
        ll Ac = 0;
        rep(i,N){
            if(bit & (1<<i)){
                Ac+=K[i];
            }
        }
        ans = min(ans, max(Ac,sum-Ac));
    }
    cout << ans << endl;
}
//3min
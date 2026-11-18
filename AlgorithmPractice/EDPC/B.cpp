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
    ll N,K;
    cin >> N >> K;
    ll h[N];
    rep(i,N)cin >> h[i];
    ll dp[N];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    repp(i,2,N){
        ll ans = (1LL<<60);
        repp(j,1,min(i+1,K+1)){
            ans = min(ans, dp[i-j] + abs(h[i-j]-h[i]));
        }
        dp[i] = ans;
    }
    cout << dp[N-1] << endl;
}
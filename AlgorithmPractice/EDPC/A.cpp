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
    ll h[N];
    rep(i,N)cin >> h[i];
    ll dp[N];
    dp[0];
    dp[1] = abs(h[1]-h[0]);
    repp(i,2,N){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[N-1] << endl;
}
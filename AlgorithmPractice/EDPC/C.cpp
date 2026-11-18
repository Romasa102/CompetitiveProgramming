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
    ll A[N],B[N],C[N];
    rep(i,N){
        cin >> A[i] >> B[i] >> C[i];
    }
    ll dp[N][3];
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];
    repp(i,1,N){
        dp[i][0] = A[i]+max({dp[i-1][1],dp[i-1][2]});
        dp[i][1] = B[i]+max({dp[i-1][0],dp[i-1][2]});
        dp[i][2] = C[i]+max({dp[i-1][0],dp[i-1][1]});
    }
    ll ans = 0;
    rep(i,3){
        ans = max(ans,dp[N-1][i]);
    }
    cout << ans << endl;
}
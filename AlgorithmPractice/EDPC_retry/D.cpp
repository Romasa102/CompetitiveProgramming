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
    ll N,W;
    cin >> N >> W;
    ll w[N],v[N];
    rep(i,N)cin >> w[i] >> v[i];
    ll dp[N+1][W+1];
    rep(i,N+1)rep(j,W+1)dp[i][j]=0;
    repp(i,1,N+1){
        repp(j,1,W+1){
            if(j-w[i-1] >= 0){
                dp[i][j] = max({dp[i][j-1],dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]});
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    /*
    rep(i,N+1){
        rep(j,W+1){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    */
    cout << dp[N][W] << endl;
}
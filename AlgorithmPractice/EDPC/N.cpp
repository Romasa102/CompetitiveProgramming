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
vector<vector<ll>> dp;
vector<ll> aSum;
vector<ll> a;
ll rec(ll l, ll r){
    if(l==r)return 0;
    if(r-l==1)return a[l]+a[r];
    if(dp[l][r]!=-1)return dp[l][r];
    ll ans = 1LL<<50;
    repp(i,l,r){
        ans = min(ans,rec(l,i)+rec(i+1,r)+(aSum[r+1]-aSum[l]));
    }
    return dp[l][r]=ans;
}
int main(){
    ll N;
    cin >> N;
    a.resize(N);
    aSum.resize(N+1);
    dp.resize(N,vector<ll>(N,-1));
    rep(i,N)cin >> a[i];
    aSum[0]=0;
    rep(i,N)aSum[i+1]=aSum[i]+a[i];
    ll ans = rec(0,N-1);
    cout << ans << endl;
}
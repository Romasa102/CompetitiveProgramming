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
ll INF = 1LL<<40;
bool comp(P a,P b){
    if(a.first<b.first)return true;
    if(a.first==b.first)return (a.second>b.second);
    return false;
}
int main(){
    ll N;
    cin >> N;
    vector<P> AB(N);
    rep(i,N)cin >> AB[i].first >> AB[i].second;
    sort(AB.begin(), AB.end(),comp);
    vector<ll> dp(N+1,INF);
    dp[0]=-1;
    rep(i,N){
        ll it = lower_bound(dp.begin(),dp.end(),AB[i].second)-dp.begin();
        dp[it]=(AB[i].second);
    }
    ll ans = -1;
    rep(i,N+1)if(dp[i]!=INF)ans++;
    cout << ans << endl;
}
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
map<ll,vector<ll>> mp;
vector<ll> dp;
ll dfs(ll x){
    if(dp[x]!=-1)dp[x];
    ll ans = 0;
    for(auto i:mp[x]){
        if(dp[i]!=-1){
            ans = max(ans,dp[i]+1);
        }else{
            ans = max(ans,dfs(i)+1);
        }
    }
    return dp[x] = ans;
}
int main(){
    ll N,M;
    cin >> N >> M;
    dp.resize(N+1,-1);
    rep(i,M){
        ll x,y;
        cin >> x >> y;
        mp[x].push_back(y);
    }
    ll ans = 0;
    repp(i,1,N+1)ans = max(ans,dfs(i));
    cout << ans << endl;
}
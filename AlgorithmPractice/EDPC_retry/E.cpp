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
    vector<vector<P>> dp(N+1);
    dp[0].push_back({0,0});
    repp(i,1,N+1){
        rep(j,dp[i].size()){
            if((*upper_bound({dp[i-1][j].first+w[i-1],0LL},dp[i-1].begin(),dp[i-1].end())).second)
        }
    }
    cout << (*(--dp[N].end())).second << endl;
}
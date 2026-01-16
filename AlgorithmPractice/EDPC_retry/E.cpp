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
    ll w[N+1],v[N+1];
    rep(i,N)cin >> w[i] >> v[i];
    vector<vector<P>> dp(N+1);
    dp[0].push_back({0,0});
    repp(i,1,N+1){
        rep(j,dp[i-1].size()){
            P target = {dp[i-1][j].first + w[i-1], 0LL};
            auto lb = *(--lower_bound(dp[i-1].begin(), dp[i-1].end(), target));

            if(dp[i].empty() ||(*(--dp[i].end())).second < dp[i-1][j].second){
                dp[i].push_back(dp[i-1][j]);
            }

            if(dp[i].empty() ||(*(--dp[i].end())).second < lb.second){
                dp[i].push_back(lb);
            }
            if(lb.second <= v[i-1] + dp[i-1][j].second){
                if(w[i-1]+dp[i-1][j].first <= W){
                    if(dp[i].empty() ||(*(--dp[i].end())).second < (v[i-1] + dp[i-1][j].second)){
                        dp[i].push_back({w[i-1]+dp[i-1][j].first,v[i-1] + dp[i-1][j].second});
                    }
                }
            }
        }
    }
    /*
    rep(i,N+1){
        rep(j,dp[i].size())cout << dp[i][j].first << ":" << dp[i][j].second << " ";
        cout << endl;
    }
    */
    cout << (*(--dp[N].end())).second << endl;
}
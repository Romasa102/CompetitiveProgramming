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
    vector<set<P>> dp(N+1);
    dp[0].insert({0,0});
    repp(i,1,N+1){
        for (auto itr = dp[i-1].begin(); itr != dp[i-1].end(); itr++){
            P cur = *itr;
            
            if(dp[i].empty() ||(*(--upper_bound(dp[i].begin(),dp[i].end(),cur))).second < cur.second){
                dp[i].insert(cur);
            }
            if((w[i-1]+cur.first) > W)continue;

            P target = {cur.first + w[i-1], 1LL<<50};
            auto lb = *(--upper_bound(dp[i-1].begin(), dp[i-1].end(), target));
            
            if(lb.second <= (v[i-1] + cur.second)){
                if((*(--dp[i].end())).second < (v[i-1] + cur.second)){
                    dp[i].insert({w[i-1]+cur.first,v[i-1] + cur.second});
                }
            }
        }
    }
    
    rep(i,N+1){
        for (auto itr = dp[i].begin(); itr != dp[i].end(); itr++){
            cout << (*itr).first << ":" << (*itr).second << " ";
        }
        cout << endl;
    }
    cout << (*(--dp[N].end())).second << endl;
}
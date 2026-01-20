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
vector<string> a;
ll xs[2] = {1,0};
ll ys[2] = {0,1};
ll H,W;

ll dfs(ll x,ll y){
    if(dp[x][y]!=-1)return dp[x][y];
    ll ans = 0;
    rep(i,2){
        if(x+xs[i]>=H ||y+ys[i]>=W)continue;
        if(a[x+xs[i]][y+ys[i]]=='#')continue;
        ll next = 0;
        if(dp[x+xs[i]][y+ys[i]]==-1){
            next = dfs(x+xs[i],y+ys[i]);
        }else{
            next = dp[x+xs[i]][y+ys[i]]; 
        }
        ans+=next;
    }
    return dp[x][y]=ans%1000000007;
}
int main(){
    cin >> H >> W;
    a.resize(H);
    dp.resize(H,vector<ll>(W,-1));
    dp[H-1][W-1]=1;
    rep(i,H)cin >> a[i];
    ll anss = dfs(0,0);
    cout <<anss%1000000007<<endl;
}
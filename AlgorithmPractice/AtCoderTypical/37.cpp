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
ll W,N;
ll segTS =1;
vector<vector<ll>> dp;
void update(ll layer, ll pos, ll x){
    ll poss = pos+segTS;
    dp[layer][poss] = x;
    while(poss>1){
        poss/=2;
        dp[layer][poss] = max(dp[layer][poss*2],dp[layer][poss*2+1]);
    }
}
ll segMax(ll layer, ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l<=st && en <= r)return dp[layer][node];
    if(en < l || r < st)return -(1LL<<45);
    return (max(segMax(layer,l,r,st,(st+en)/2,node*2),
                segMax(layer,l,r,(st+en)/2+1,en,node*2+1)));
}
int main(){
    cin >> W >> N;
    while(segTS<(W+1))segTS*=2;
    dp.resize(N+1,vector<ll>(2*segTS,-(1LL<<45)));
    ll L[N],R[N],V[N];
    rep(i,N)cin >> L[i] >> R[i] >> V[i];
    dp[0][segTS]=0;
    update(0, 0, 0);
    repp(i,1,N+1){
        rep(j,W+1){
            //dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-L],dp[i-1][j-R])
            ll rmq = -(1LL<<45);
            if(j-L[i-1]>=0 && segMax(i-1,max(0LL,j-R[i-1]),j-L[i-1]) != -(1LL<<45)){
                rmq = V[i-1]+segMax(i-1,max(0LL,j-R[i-1]),j-L[i-1]);
            }
            ll newV = max({dp[i-1][j+segTS],rmq});
            update(i,j,newV);

            //cout << dp[i][segTS+j] << " ";
        }//cout << endl;
    }
    if(dp[N][segTS+W] == -(1LL<<45)){
        cout << -1 << endl;
    }else{    
        cout << dp[N][segTS+W] << endl;
    }
}
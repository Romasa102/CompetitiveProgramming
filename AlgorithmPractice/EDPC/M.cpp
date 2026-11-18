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
    ll N,K;
    cin >> N >> K;
    ll a[N];
    rep(i,N)cin >> a[i];
    vector<vector<ll>> dp(N+1,vector<ll>(K+2,0));
    
    repp(i,1,K+2)dp[0][i]=1;
    repp(i,1,N+1){
        vector<ll> cur(K+1);
        rep(j,K+1){
            cur[j] = dp[i-1][j+1]-dp[i-1][max(0LL,(j-a[i-1]))];
            while(cur[j]<0)cur[j]+=1000000007;
        }
        dp[i][0]=0;
        repp(j,1,K+2){
            dp[i][j]=dp[i][j-1]+cur[j-1];
            dp[i][j]%=1000000007;
        }
        if(i==N)cout << cur[K]%1000000007 << endl;
    }
}
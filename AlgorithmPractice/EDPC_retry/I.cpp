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
    ll N;cin>>N;
    double p[N];rep(i,N)cin >> p[i];
    double dp[N+1][N+1];
    rep(i,N+1)rep(j,N+1)dp[i][j]=0;
    dp[0][0]=1;
    repp(i,1,N+1){
        rep(j,N+1){
            dp[i][j]=dp[i-1][j]*(1-p[i-1])+(dp[i-1][j-1]*p[i-1]);
        }
    }
    double ans = 0;
    repp(j,(N+1)/2,N+1){
        ans+=dp[N][j];
    }
    cout << setprecision(15);
    cout << ans << endl;
}
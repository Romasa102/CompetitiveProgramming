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
    ll A[N],B[N];
    rep(i,N)cin >> A[i] >> B[i];
    vector<vector<ll>> dp(N,vector<ll>(K*2+1,0));
    dp[0][0] = A[0];
    if(K!=0){
        dp[0][1] = B[0];
    }
    repp(i,1,N){
        rep(j,K*2+1){//even it would be to add A[i]; odd B[i]
            if(j==0){
                dp[i][j] = dp[i-1][j]+A[i];
                continue;
            }
            if(j%2 == 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + A[i];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + B[i];
            }
        }
    }
    ll ans = 0;
    rep(j,K*2+1){
        rep(i,N){
            //cout << dp[i][j] << " ";
        }//cout << endl;
    }
    rep(i,K*2+1){
        ans = max(ans, dp[N-1][i]);
    }
    cout << ans << endl;
}
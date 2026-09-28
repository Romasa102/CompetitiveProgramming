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
ll elp = 0;
int main(){
    string S,T;
    cin >> S >> T;
    ll right = T.size();
    dp.resize(S.size(),vector<ll>(T.size(),0LL));
    ll ans = 0;
    rep(i,S.size()){
        rep(j,T.size()){
            if(S[i] == T[j]){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }else if(j==0){
                    dp[i][j] = dp[i-1][j] + 1;
                }else if(i>0){                
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }else{
                if(i>0)dp[i][j] = dp[i-1][j];
            }
            cout << dp[i][j] << " ";
        }cout << endl;
        rep(j,T.size()-1){
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
}
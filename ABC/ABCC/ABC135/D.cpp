#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
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
const ll MOD = 1000000007;
int main(){
    string S;
    cin >> S;
    ll dp[S.size() + 1][13]; //digit (from top), mod
    memset(dp,0,sizeof(dp));
    ll modThirteen[110000];
    modThirteen[0] = 1;
    modThirteen[1] = 10;
    repp(i,2,110000){
        modThirteen[i] = (modThirteen[i-1] * 10) % 13;
    }
    dp[0][0] = 1;
    repp(i,1,S.size()+1){
        if(S[i-1] == '?'){
            rep(j,10){
                ll curMod = (j * modThirteen[S.size()-i]) % 13;
                rep(k,13){
                    dp[i][(k + curMod) % 13] += dp[i-1][k];
                    dp[i][(k + curMod) % 13] %= MOD; 
                }
            }
        }else{
            ll curN = S[i-1] - '0';
            ll curMod = (curN * modThirteen[S.size()-i]) % 13;
            rep(j,13){
                dp[i][(j + curMod) % 13] += dp[i-1][j];
                dp[i][(j + curMod) % 13] %= MOD;
            }
        }
    }
    cout << dp[S.size()][5] % MOD << endl;
}
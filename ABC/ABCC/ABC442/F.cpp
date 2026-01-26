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
    ll N;cin >> N;
    string S[N];
    rep(i,N)cin >> S[i];
    vector<vector<ll>> dp(N+1,vector<ll> (N+1,1LL<<40));
    vector<vector<ll>> mindp(N+1,vector<ll>(N+2,1LL<<40));
    rep(i,N+2)mindp[0][i]=0;
    rep(i,N){
        vector<ll> white(N+1);
        vector<ll> black(N+2);
        white[0]=0;
        black[N+1]=0;
        repp(j,1,N+1){
            if(S[i][j-1]=='.'){
                white[j]=white[j-1]+1;
            }else{
                white[j]=white[j-1];
            }
        }
        for(ll j = N;j>0;j--){
            if(S[i][j-1]=='#'){
                black[j]=black[j+1]+1;
            }else{
                black[j]=black[j+1];
            }
        }
        black[0]=black[1];
        rep(j,N+1){
            dp[i][j] =(j-white[j])+(N-j-(black[j+1])) + mindp[i][j];
        }
        for(ll j = N;j>=0;j--){
            mindp[i+1][j]=min(dp[i][j],mindp[i+1][j+1]);
        }
        /*
        cout << endl << "w :";
        rep(j,N+1)cout << white[j] << " ";
        cout << endl << "b :";
        rep(j,N+1)cout << black[j] << " ";
        cout << endl << "dp:";
        rep(j,N+1)cout << dp[i][j] << " ";*/
    }
    ll ans = 1LL<<40;
    rep(i,N+1)ans = min(ans,dp[N-1][i]);
    cout << ans <<endl;
}
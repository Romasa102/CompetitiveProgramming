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
vector<vector<vector<ll>>> dp; 
vector<ll> a;
vector<vector<bool>> visited; 
void dfs(ll i,ll j){
    /*0 mean max first which is default*/
    if(i==j){
        dp[i][j][0]=a[i];
        dp[i][j][1]=-a[i];
        return;
    }
    if(!visited[i+1][j]){
        visited[i+1][j]=true;
        dfs(i+1,j);
    }
    if(!visited[i][j-1]){
        visited[i][j-1]=true;
        dfs(i,j-1);
    }
    dp[i][j][0] = max({
        a[j] + dp[i][j-1][1],
        //-a[j] + dp[i][j-1][0],
        a[i] + dp[i+1][j][1],
        //-a[i] + dp[i+1][j][0]
        }
    );

    dp[i][j][1] = min({
        //a[j] + dp[i][j-1][1],
        -a[j] + dp[i][j-1][0],
        //-a[i] + dp[i+1][j][1],
        -a[i] + dp[i+1][j][0]
    });
}
int main(){
    ll N;
    cin >> N;
    visited.resize(N,vector<bool> (N,false));
    a.resize(N,0);
    rep(i,N)cin >> a[i];
    // if last time is tail or if last itme is head. try to max.
    dp.resize(N,vector<vector<ll>>(N,vector<ll>(2,0)));

    dfs(0,N-1);
    cout << dp[0][N-1][0] << endl;
}
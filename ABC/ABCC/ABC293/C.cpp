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
ll H,W;
vector<vector<ll>> A;
ll dfs(ll x,ll y,set<ll> path){
    if(path.find(A[x][y])!=path.end())return 0;
    if(x==(H-1) && y == (W-1))return 1;
    auto pathC = path;
    pathC.insert(A[x][y]);
    ll ans = 0;
    if(x+1<H){
        ans+=dfs(x+1,y,pathC);
    }
    if(y+1<W){
        ans+=dfs(x,y+1,pathC);
    }
    return ans;
}
int main(){
    cin >> H >> W;
    A.resize(H,vector<ll>(W));
    rep(i,H)rep(j,W)cin>>A[i][j];
    cout <<  dfs(0,0,set<ll>()) << endl;
}
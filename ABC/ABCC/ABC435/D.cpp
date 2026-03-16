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
vector<vector<ll>> path;
vector<bool> black;
void dfs(ll x){
    if(black[x])return;
    black[x]=true;
    for(ll u:path[x]){
        if(!black[u])dfs(u);
    }
}
int main(){
    ll N,M;cin >> N >> M;
    ll X[M],Y[M];
    black.resize(N,false);
    path.resize(N);
    rep(i,M){
        cin >> X[i] >> Y[i];
        X[i]--;Y[i]--;
        path[Y[i]].push_back(X[i]);
    }
    ll Q;cin >> Q;
    rep(_,Q){
        ll task;cin >> task;
        ll v;cin >> v;v--;
        if(task==1){
            dfs(v);
        }else{
            if(black[v]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
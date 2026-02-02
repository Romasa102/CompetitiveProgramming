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
map<ll,vector<ll>> path;
vector<bool> black;
void dfs(ll x){
    black[x]=true;
    for(auto y:path[x]){
        if(black[y])continue;
        dfs(y);
    }
}
int main(){
    ll N,M;
    cin  >> N >> M;
    ll X[M],Y[M];
    rep(i,M){
        cin >> X[i] >> Y[i];
        path[Y[i]-1].push_back(X[i]-1);
    }
    black.resize(N);
    ll Q;
    cin >> Q;
    while(Q--){
        ll t,v;
        cin >> t >> v;
        v--;
        if(t==1){
            dfs(v);
            //make v to black
        }else{
            if(black[v]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            //track if it is possible to reach black from v
        }
    }
}
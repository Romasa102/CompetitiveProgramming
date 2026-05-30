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
map<P,P> parent;
P parents(P a){
    if(parent[a] == a)return a;
    return parent[a] = parents(parent[a]);
}
void merge(P a, P b){
    parent[parents(a)] = parents(b);
}
int main(){
    ll H,W;cin >> H >> W;
    
    string S[H];
    rep(i,H)cin >> S[i];
    rep(i,H)rep(j,W)parent[{i,j}] = {i,j};
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '.'){
                if(S[i-1][j] == '.'){
                    merge({i,j},{i-1,j});
                }
                if(S[i][j-1] == '.'){
                    merge({i,j},{i,j-1});
                }
            }
        }
    }
    set<P> ans;
    set<P> rmvL;
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '.'){
                ans.insert(parents({i,j}));
                if(i == H-1 || i == 0 || j == 0 || j == W-1){
                    rmvL.insert(parents({i,j}));
                }
            }
        }
        cout << endl;
    }
    for(auto i : rmvL){
        ans.erase(i);
    }
    cout << ans.size() << endl;
}
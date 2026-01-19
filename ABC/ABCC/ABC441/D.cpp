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
    ll N,M,L,S,T;
    cin >> N >> M >> L >> S >> T;
    map<ll,vector<P>> edge;
    rep(i,M){
        ll U,V,C;
        cin >> U >> V >> C;
        edge[U-1].push_back({V-1,C});
    }
    queue<pair<ll,P>> Q;
    Q.push({0,{0,0}});
    set<ll> ans;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        ll curDis = cur.second.first;
        ll curCost = cur.second.second;
        if(curDis == L){
            if(S <= curCost  && curCost <= T){
                ans.insert(cur.first);
            }
            continue;
        }
        if(curDis >= L)continue;
        if(curCost > T)continue;
        rep(i,edge[cur.first].size()){
            ll to = edge[cur.first][i].first;
            ll cost = edge[cur.first][i].second;
            Q.push({to,{curDis+1,curCost+cost}});
        }
    }
    for(auto it = ans.begin();it != ans.end();++it){
        cout << *it +1 << " ";
    }cout << endl;
}
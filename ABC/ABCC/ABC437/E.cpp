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

map<ll,set<P>> tr;
void dfsP(ll x){
    auto it = tr[x].begin();
    while(it!=tr[x].end()){
        ll ind = (*it).second;
        ll val = (*it).first;
        cout << ind << " ";
        auto next_it = next(it);
        while(next_it != tr[x].end()&& (*next_it).first==val){
            ll next_ind = (*next_it).second;
            cout << next_ind << " ";
            next_it = tr[x].erase(next_it); 
            tr[ind].insert(tr[next_ind].begin(), tr[next_ind].end());
        }
        ++it;
        dfsP(ind);
    }
}
int main(){
    ll N;
    cin>>N;
    repp(i,1,N+1){
        ll x,y;
        cin >> x >> y;
        tr[x].insert({y,i});
    }
    dfsP(0);
}
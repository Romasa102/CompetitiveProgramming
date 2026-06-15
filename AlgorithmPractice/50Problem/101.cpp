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
    ll N;
    cin >> N;
    set<ll> Xcoords;
    set<ll> Ycoords;
    vector<pair<P,P>> coords(N);
    rep(i,N){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        coords[i].first.first = x1;
        coords[i].first.second = y1;
        coords[i].second.first = x2;
        coords[i].second.second = y2;
        Xcoords.insert(x1);
        Xcoords.insert(x2);
        Ycoords.insert(y1);
        Ycoords.insert(y2);
    }
    vector<vector<ll>> compmap(Xcoords.size(),vector<ll> (Ycoords.size()));
    
    vector<pair<P,P>> coords(N);
    
}
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
    ll N,M;
    cin >> N >> M;
    set<ll> juice;
    rep(i,M)juice.insert(i+1);
    rep(i,N){
        ll L;
        cin >> L;
        ll ans = 0;
        rep(j,L){
            ll x;
            cin >> x;
            if(ans==0 && juice.find(x)!=juice.end()){
                juice.erase(x);
                ans = x;
            }
        }
        cout << ans << endl;
    }
}
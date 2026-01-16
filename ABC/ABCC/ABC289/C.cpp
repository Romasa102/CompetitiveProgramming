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
    vector<set<ll>> mp(M);
    rep(i,M){
        ll c;
        cin >> c;
        rep(j,c){
            ll k;
            cin >> k;
            mp[i].insert(k);
        }
    }
    ll ans = 0;
    for(ll bit = 0; bit < (1<<M);bit++){
        set<ll> st;
        rep(i,M){
            if(bit & (1<<i)){
                st.insert(mp[i].begin(),mp[i].end());
            }
        }
        if(st.size() == N)ans++;
    }
    cout << ans << endl;
}
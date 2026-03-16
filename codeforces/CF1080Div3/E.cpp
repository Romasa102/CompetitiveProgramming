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
ll n;
map<ll,vector<ll>> mp;
vector<ll> anss;
map<P,ll> emp;
ll dfs(ll x){
    ll ans = 0;
    for(ll nd : mp[x]){
        if(nd==0)continue;

        ll dis = (dfs(nd));
        emp[{x,nd}]=dis;
        ans+=(dis+1);
    }
    return (ans+1);
}
void ansdisc(ll x,ll cumulativeS){
    ll ans = cumulativeS;
    for(ll nd:mp[x]){
        if (nd == 0) continue;
        anss[nd]=(ans+emp[{x,nd}])%1000000007;
        ansdisc(nd,ans+emp[{x,nd}]);
    }
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        anss.resize(n+1,0);
        rep(i,n){
            ll l,r;
            cin >> l >> r;
            mp[i+1].push_back(l);
            mp[i+1].push_back(r);
        }
        mp[0].push_back(1);
        dfs(0);
        ansdisc(0,0);
        rep(i,n){
            cout<< anss[i+1]%1000000007 << " ";
        }cout << endl;
    }
}
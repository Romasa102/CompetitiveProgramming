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
    ll t;cin >> t;
    rep(_,t){
        ll n;cin>>n;
        ll a[n];rep(i,n)cin >> a[i];
        map<ll,vector<ll>> score;
        set<ll> key;
        rep(i,n-4){
            score[a[i]+a[i+2]-a[i+4]].push_back(i);
            key.insert(a[i]+a[i+2]-a[i+4]);
        }
        ll ans = 0;
        for(auto i : key){
            sort(score[i].begin(),score[i].end());
            for(auto j : score[i]){
                ll sub = 0;
                if (binary_search(score[i].begin(), score[i].end(), j + 2)) sub++;
                if (binary_search(score[i].begin(), score[i].end(), j + 4)) sub++;
                ans += (score[i].end()- upper_bound(score[i].begin(),score[i].end(),j)) -sub;
            }
        }
        cout << ans << endl;
    }
}
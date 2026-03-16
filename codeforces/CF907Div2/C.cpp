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
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i,n)cin >> a[i];
        sort(a,a+n,greater<ll>());
        vector<ll> totalS(n+1,0);
        repp(i,1,n+1){
            totalS[i]=totalS[i-1]+a[i-1];
        }
        auto it = (--upper_bound(totalS.begin(),totalS.end(),totalS[n]/2));
        ll remaindTP = totalS[n]/2-(*it);
        if(remaindTP>0)remaindTP--;
        ll numOfT = (it-totalS.begin());
        ll numOfF = totalS[n]-(*it);
        cout << numOfF+numOfT-remaindTP << endl;
    }
}
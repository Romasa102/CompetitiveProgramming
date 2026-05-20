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
    ll t;
    cin >> t;
    rep(_,t){
        ll n;
        cin >> n;
        ll w[n];
        ll modR[3];
        rep(i,3)modR[i]=0;
        rep(i,n){
            cin >> w[i];
            modR[w[i]%3]++;
        }
        ll ans = modR[0];
        if(modR[2] > modR[1]){
            ans += modR[1];
            modR[2]-=modR[1];
            ans+=modR[2]/3;
        }else{
            ans+=modR[2];
            modR[1]-=modR[2];
            ans+=modR[1]/3;
        }
        cout << ans << endl;
    }
}
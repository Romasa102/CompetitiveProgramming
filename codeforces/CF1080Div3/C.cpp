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
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i,n)cin >> a[i];
        vector<bool> ok(n-1,true);
        rep(i,n-1){
            if(a[i]==a[i+1]||(7-a[i])==a[i+1]){
                ok[i]=false;
            }
        }
        ll ans = 0;
        rep(i,n-1){
            if(ok[i]==false && (i+1)<(n-1) && ok[i+1]==false){
                ans++;
                ok[i]=true;
                ok[i+1]=true;
            }else if(ok[i]==false){
                ans++;
                ok[i]=true;
            }
        }
        cout << ans << endl;
    }
}
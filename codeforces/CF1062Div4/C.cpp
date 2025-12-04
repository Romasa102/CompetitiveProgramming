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
        ll a[n];
        ll evenCount = 0;
        rep(i,n){
            cin >> a[i];
            if(a[i]%2){
                evenCount++;
            }
        }
        if(evenCount==n | evenCount == 0){
            rep(i,n){
                cout << a[i] << " ";
            }cout << endl;
            continue;
        }
        sort(a,a+n);
        rep(i,n){
            cout << a[i] << " ";
        }cout << endl;
    }
}
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
        ll n,k,x;
        cin >> n >> k >> x;
        double a[n];
        rep(i,n){
            cin >> a[i];
        }
        double distance[n+1];
        sort(a, a+n);
        distance[0] = a[0];
        distance[n] = x - a[n-1];
        rep(i,n-1){
            distance[i+1] = (a[i+1]- a[i])/2;
        }
        sort(distance, distance+n+1);
        
    }
}
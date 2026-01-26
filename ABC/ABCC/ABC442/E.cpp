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

const long double PI = acosl(-1.0); 
const long double EPS = 1e-18; 


int main(){
    ll N,Q;
    cin >> N >> Q;
    
    long double ang[N];
    vector<pair<long double, ll>> angs;
    
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        ang[i] = atan2l((long double)y, (long double)x);
        
        ang[i] = -ang[i];
        ang[i] += PI / 2.0;
        if(ang[i] < 0) ang[i] += 2.0 * PI;
        
        angs.push_back({ang[i], i});
        angs.push_back({ang[i] + 2.0 * PI, i});
    }
    
    sort(angs.begin(), angs.end());
    
    rep(i,Q){
        ll A,B;
        cin >> A >> B;
        A--; B--;
        long double angA = ang[A];
        long double angB = ang[B];

        if (angA <= angB) {
            cout << upper_bound(angs.begin(), angs.end(), make_pair(angB + EPS, 1LL<<30)) 
                  - lower_bound(angs.begin(), angs.end(), make_pair(angA - EPS, 0LL)) << "\n";
        } else {
            cout << upper_bound(angs.begin(), angs.end(), make_pair(angB + 2.0 * PI + EPS, 1LL<<30)) 
                  - lower_bound(angs.begin(), angs.end(), make_pair(angA - EPS, 0LL)) << "\n";
        }
    }
}
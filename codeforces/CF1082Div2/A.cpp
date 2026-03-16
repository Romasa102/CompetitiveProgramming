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
        ll x,y;
        cin >> x >> y;
        ll minX = abs(y)*2;
        if(y<0){
            minX*=2;
        }
        if(minX>x){
            cout << "NO" << endl;
            continue;
        }
        if((x-minX)%3==0){
            cout << "YES" << endl;
            continue;
        }cout << "NO" << endl;
    }
}
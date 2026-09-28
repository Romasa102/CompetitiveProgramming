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
    ll l,r;
    cin >> l >> r;
    if(l == r){
        cout << l+2*r << endl;
    }else if(l == r+1){
        cout << l + r << endl;
    }else if(l == r+2){
        cout << (l + r)*2 - (l-1) << endl;
    }
    else{
        cout << min((l+r-1)*(l+r-2),2* (l+r)) << endl;
    }
}
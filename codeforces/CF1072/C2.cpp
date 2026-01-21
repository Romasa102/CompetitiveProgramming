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
        ll n,k;
        cin >> n >> k;
        bool solved = false;
        for(ll ct=0, l = n, r = n; l > 0; ct++,l/=2, r=(r+1)/2){
            if(l <= k && k <= r){
                cout << ct << endl;
                solved = true;
                break;
            }
        }
        if(!solved)cout << -1 << endl;
    }
}
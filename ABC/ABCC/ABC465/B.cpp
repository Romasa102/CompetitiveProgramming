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
    ll X,Y,L,R,A,B;
    cin >> X >> Y >> L >> R >> A >> B;
    vector<ll> cost(24);
    rep(i,24){
        if(i < L || (R-1) < i){
            cost[i] = Y;
        }else{
            cost[i] = X;
        }
    }
    ll ans = 0;
    repp(i,1,24){
        //cout << cost[i] << " ";
    }//cout << endl;
    repp(i,A,B){
        ans += cost[i];
    }
    cout << ans << endl;
}
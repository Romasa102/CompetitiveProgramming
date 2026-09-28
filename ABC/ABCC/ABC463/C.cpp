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
    ll N;cin >> N;
    vector<P> LH(N);
    rep(i,N)cin >> LH[i].second >> LH[i].first;
    sort(LH.begin(),LH.end(),greater<P>());
    ll curMax = 0;
    rep(i,N){
        if(LH[i].second > curMax){
            curMax = LH[i].second;
        }else{
            LH[i].second = curMax;
        }
    }
    ll Q;
    cin >> Q;
    sort(LH.begin(),LH.end());
    rep(_,Q){
        ll T;
        cin >> T;
        P time = {T,1000000000};
        cout << (*upper_bound(LH.begin(),LH.end(),time)).second << endl;;
    }
}
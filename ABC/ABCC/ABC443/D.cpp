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
    ll T;cin >> T;
    while(T--){
        ll N;cin >> N;
        ll R[N];
        rep(i,N)cin >> R[i];
        vector<ll> minP(N);
        rep(i,N){
            minP[i]=R[i];
        }
        repp(i,1,N){
            minP[i]=min(minP[i],minP[i-1]+1);
        }
        for(ll i = N-2;i>=0;i--){
            minP[i]=min(minP[i],minP[i+1]+1);
        }
        ll ans = 0;
        rep(i,N){
            ans += abs(minP[i]-R[i]);
        }
        cout << ans << endl;
    }
}
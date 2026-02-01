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
    ll N,T;
    cin >> N >> T;
    ll A[N+1];A[N]=T;
    rep(i,N)cin >> A[i];
    ll latestopen=0;
    ll ans=0;
    rep(i,N+1){
        if(latestopen<A[i]){
            ans+=(A[i]-latestopen);
            latestopen=A[i]+100;
        }
    }
    cout << ans << endl;
}
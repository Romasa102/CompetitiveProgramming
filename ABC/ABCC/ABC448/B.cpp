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
    ll N,M;
    cin >> N >> M;
    ll C[M];
    rep(i,M)cin >> C[i];
    ll A[N],B[N];
    rep(i,N){
        cin >> A[i] >> B[i];
        A[i]--;
    }
    ll ans = 0;
    rep(i,N){
        ans += min(C[A[i]],B[i]);
        C[A[i]] = max(C[A[i]]-B[i],0LL);
    }
    cout << ans << endl;
}
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
    ll A[N];
    vector<ll> B(M);
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];
    sort(A,A+N);
    sort(B.begin(),B.end());
    ll totalB = 0;
    rep(i,M)totalB+=B[i];
    ll sumB[M+1];
    sumB[0] = 0;
    repp(i,1,M+1)sumB[i] = sumB[i-1] + B[i-1];
    ll ans = 0;
    rep(i,N){
        ll pos = upper_bound(B.begin(),B.end(),A[i]) - B.begin();
        ans += (A[i] * (pos)) - sumB[pos];
        ans += (totalB - sumB[pos]) - (A[i] * (M-pos));
        ans %= 998244353;
    }
    cout << ans % 998244353 << endl;
}
//23min
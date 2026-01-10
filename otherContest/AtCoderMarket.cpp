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
    ll N;
    cin >> N;
    ll A[N],B[N];
    rep(i,N)cin >> A[i] >> B[i];
    ll ans =0;
    rep(i,N)ans += (B[i]-A[i]);
    ll a = N;
    ll b = 0;
    ll c = N;
    ll d = 0;
    ll curSE = 0;
    ll curEE = 0;
    sort (A,A+N);
    sort (B,B+N);
    rep(i,N)curEE += (B[N-1]-B[i]);
    rep(i,N)curSE += (A[i] - A[0]);
    while(b-a < 0){
        b++;a--;
        curSE += (b-a) * (A[b]-A[b-1]);
    }
    while(d-c<0){
        c--;d++;
        curEE += (d-c) * (B[c]-B[c-1]);
    }
    rep(i,N){
        ans += abs(A[i] - A[b-1]);
        ans += abs(B[i] - B[c]);
    }
    cout << ans<< endl;
}

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
    vector<ll> A(N);
    vector<ll> B(M);
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];

    sort(A.begin(),A.end(),greater<ll>());
    rep(i,N)A[i]*=2;

    sort(B.begin(),B.end());
    ll ans = 0;
    rep(i,N){
        if(B.empty())break;
        auto it = upper_bound(B.begin(),B.end(),A[i]);
        if(it!=B.begin())it--;
        if(*(it) <=A[i]){
            B.erase(it,B.end());
            ans++;
        }
    }
    cout << ans << endl;
}

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
    ll T;
    cin >> T;
    rep(_,T){
        ll N,W;
        cin >> N >> W;
        ll C[N];
        rep(i,N)cin >> C[i];
        ll remainder[2*W];
        rep(i,2*W)remainder[i]=0;
        rep(i,N)remainder[i%(2*W)]+=C[i];
        ll remainderC[2*W+1];
        remainderC[0]=0;
        repp(i,1,2*W+1)remainderC[i]=remainderC[i-1]+remainder[i-1];
        ll ansM = 1LL<<60;
        rep(i,W+1){
            //cout << "pO" << i+W << " and " << i << " ";
            ansM = min(ansM,remainderC[i+W]-remainderC[i]);
        }
        rep(i,W){
            //cout << "pO" << i << " and " << 0 << "+" << W*2 << " and " << W+i;
            ansM = min(ansM ,(remainderC[i]-remainderC[0]) + remainderC[W*2]-remainderC[W+i]);
        }
        cout << ansM << endl;
    }
}

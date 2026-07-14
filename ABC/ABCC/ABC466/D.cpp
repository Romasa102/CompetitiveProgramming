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
    ll R[M];
    ll C[M];
    rep(i,M){
        cin >> R[i] >> C[i];
    }
    vector<bool> ban_rows(N,false);
    vector<bool> ban_cols(N,false);
    ll ans = 0;
    for(ll i = M-1; i >= 0; i--){
        if(!ban_rows[R[i]] && !ban_cols[C[i]]){
            ans++;
        }
        ban_rows[R[i]]=true;
        ban_cols[C[i]]=true;
    }
    cout << ans << endl;
}
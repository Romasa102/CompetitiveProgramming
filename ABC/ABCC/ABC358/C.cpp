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
    string S[N];
    rep(i,N)cin >> S[i];
    ll ans = 1LL<<32;
    for(ll bit = 0; bit < (1<<N);++bit){
        set<ll> st;
        ll ct = 0;
        rep(i,N){
            if(bit & (1<<i)){
                ct++;
                rep(j,M){
                    if(S[i][j] == 'o'){
                        st.insert(j);
                    }
                }
            }
        }
        if(st.size() == M){
            ans = min(ans,ct);
        }
    }
    cout << ans << endl;
}
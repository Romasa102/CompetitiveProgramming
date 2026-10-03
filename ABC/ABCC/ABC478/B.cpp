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
    ll N,V;
    cin >> N >> V;
    ll W[N];
    rep(i,N)cin >> W[i];
    ll ans = 0;
    rep(i,N-2){
        repp(j,i+1,N-1){
            repp(k,j+1,N){
                if(i+j+k+3 <= V){
                    ans = max(ans,W[i]+W[j]+W[k]);
                }
            }
        }
    }
    cout << ans << endl;
}
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
        ll N;
        cin >> N;
        ll W[N],Po[N];
        rep(i,N)cin >> W[i] >> Po[i];
        ll totalP = 0;
        ll totalW = 0;
        ll D[N];
        rep(i,N){
            totalP += Po[i];
            totalW += W[i];
            D[i] = Po[i] + W[i];
        }
        sort(D,D+N);
        ll ans = N;
        rep(i,N){
            if(totalP - D[i] >= 0){
                totalP -= D[i];
            }else{
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}
//16
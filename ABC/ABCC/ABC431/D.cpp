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
    ll W[N],H[N],B[N];
    rep(i,N){
        cin >> W[i] >> H[i] >> B[i];
    }
    ll HWD[N];
    rep(i,N){
        HWD[i] = H[i] - B[i];
    }
    ll sumW = 0;
    ll ans = 0;
    rep(i,N){
        ans+=B[i];
    }
    rep(i,N)sumW+=W[i];
    ll headdp[N+1][sumW/2+1];
    rep(i,N+1){
        rep(j,sumW/2+1){
            headdp[i][j] = 0;
        }
    }
    repp(i,1,N+1){
        rep(j,sumW/2+1){
            if(j < W[i-1]){
                headdp[i][j] = headdp[i-1][j];
            }else{
                headdp[i][j] = max(max(headdp[i-1][j],headdp[i-1][j-W[i-1]]+HWD[i-1]),headdp[i][j-1]);
            }
        }
    }
    cout << headdp[N][sumW/2] + ans << endl;
}
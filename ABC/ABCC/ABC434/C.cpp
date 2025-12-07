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
        ll N,H;
        cin >> N >> H;
        ll t[N],l[N],u[N];
        rep(i,N)cin >> t[i] >> l[i] >> u[i];
        ll L,U;
        L = H;U=H;
        ll curT = 0;
        bool possible = true;
        rep(i,N){
            if((u[i]<(L-(t[i]-curT)))||l[i]>(U+(t[i]-curT))){
                possible = false;
            }
            L = max(L-(t[i]-curT),l[i]);
            U = min(U+(t[i]-curT),u[i]);

            curT = t[i];
        }
        if(possible){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

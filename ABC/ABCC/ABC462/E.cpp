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
    ll T;cin >>T;
    rep(_,T){
        ll A,B,X,Y;
        cin >> A >> B >> X >> Y;
        X = abs(X);Y=abs(Y);
        ll ans = 0;
        ans = min(A,B) * (min(X,Y) * 2);
        ll remain = max(X,Y) - min(X,Y);
        ll oddC = (remain+1)/2;
        ll evenC = (remain)/2;
        if(3*A < B){
            if(X>Y){
                ans += oddC * A;
                ans += evenC * 3 * A;
            }else{
                ans += oddC * 3 * A;
                ans += evenC * A;
            }
        }else if(3*B < A){
            if(X>Y){
                ans += oddC * 3 * B;
                ans += evenC * B;
            }else{
                ans += oddC * B;
                ans += evenC * 3 * B;
            }
        }else{
            if(X>Y){
                ans += oddC * A;
                ans += evenC * B;
            }else{
                ans += oddC * B;
                ans += evenC * A;
            }
        }
        cout << ans << endl;
    }
}
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
    ll t;
    cin >> t;
    ll P10[19];
    P10[0] = 1;
    for (int i = 1; i < 19; i++) P10[i] = P10[i-1] * 10;
    rep(_,t){
        ll a,n;
        cin >> a >> n;
        ll d[n];
        rep(i,n)cin >> d[i];
        ll digLen = to_string(a).length();
        ll UB = 0;
        ll LB = 0;
        rep(j,digLen+1){
            UB += P10[j] * min(d[0],d[1]);
        }
        
        rep(j,digLen-1){
            LB += P10[j] * max(d[0],d[1]);
        }
        
        ll minDiff = min(abs(UB-a),abs(LB-a));
        cout << LB << " " << UB << endl;
        LB = 0;
        UB = 0;
        if(d[0]>d[1])swap(d[0],d[1]);
        string s = to_string(a);
        for(ll i = digLen-1; i>= 0; i--){
            if((s[i]-'0')== d[0]){
                LB += P10[i] * d[0];
            }else if((s[i]-'0')==d[1]){
                UB += P10[i] * d[1];
            }else{
                if(d[0] >= (s[i]-'0')){
                    for(ll j = i; j>= 0; j--){
                        LB += P10[j] * d[0];
                        UB += P10[j] * d[0];
                    }
                    break;
                }else if(d[1]>=(s[i]-'0')){
                    LB += d[0] * P10[i];
                    UB += d[1] * P10[i];

                    for(ll j = i-1; j>= 0; j--){
                        LB += P10[j] * d[1];
                        UB += P10[j] * d[0];
                    }
                }else{
                    for(ll j = i; j>= 0; j--){
                        LB += P10[j] * d[1];
                        UB += P10[j] * d[1];
                    }
                }
                break;
            }
        }
        minDiff = min({minDiff,abs(a-UB),abs(a-LB)});
        cout << minDiff << "\n";
    }
}
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
    string S;
    cin >> N >> S;
    ll ans = 0;
    if(N == 1 && S[0] == 'x'){
        cout << 1 << endl;
    }
    rep(i,N){
        if(i==0){
            if(S[i] == 'x' && S[i+1] == 'x'){
                ans++;
            }
        }else if(i==N-1){
            if(S[i] == 'x' &&  S[i-1] == 'x'){
                ans++;
            }
        }
        else if(S[i] == 'x' && S[i+1] == 'x' && S[i-1] == 'x'){
            ans ++;
        }

    }
    cout << ans << endl;
}
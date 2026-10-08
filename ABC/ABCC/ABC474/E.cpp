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
        ll A[N],B[N];
        ll ans = 0;
        vector<ll> diff;
        ll minV = 1LL<<40;
        rep(i,N){
            cin >> A[i] >> B[i];
            diff.push_back(A[i]-B[i]);
            ans+=A[i];
            minV = min(minV,A[i]);
        }
        sort(diff.begin(),diff.end());
        rep(i,N/2){
            ans -= diff.back();
            diff.pop_back();
        }
        ll extra;
        if(N%2==0){
            extra = minV*2;
        }else{
            extra = minV;
        }
        while(diff.back() > extra){
            ans -= diff.back();
            ans += extra;
            diff.pop_back();
            extra = minV*2;
        }
        cout << ans << endl;
    }
}
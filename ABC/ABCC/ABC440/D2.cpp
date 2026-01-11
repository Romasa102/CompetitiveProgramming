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
    ll N,Q;
    cin >> N >> Q;
    ll A[N];
    rep(i,N)cin >> A[i];
    sort(A,A+N);
    rep(_,Q){
        ll X,Y;
        cin >> X >> Y;
        ll s = lower_bound(A,A+N,X) - A;
        ll left,right;
        left = N;
        right = s-1;
        ll t = N;
        while(right+1 < left){
            ll med = (right + left) / 2;
            if((A[med] - X +1) - (med - s + 1) >= Y){
                left = med;
            }else{
                right = med;
            }
            t = left;
        }
        cout << X + (Y-1) + (t - s + 0) << endl;
    }
}
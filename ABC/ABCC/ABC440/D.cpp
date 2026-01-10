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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());
    rep(_, Q){
        ll X, Y;
        cin >> X >> Y;
        ll curP = X;
        ll curA = X + Y - 1;
        auto PO = lower_bound(A.begin(), A.end(), curP);
        auto AO = PO;
        while(curA + 1 != curP){
            AO = upper_bound(PO, A.end(), curA);
            if(AO <= PO) break;
            curP = curA + 1;
            curA += (AO - PO);
            PO = AO;
        }
        cout << curA << endl;
    }
}

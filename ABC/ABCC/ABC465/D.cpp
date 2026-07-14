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
        ll X,Y,K;
        cin >> X >> Y >> K;
        vector<ll> Xdiv;
        vector<ll> Ydiv;
        Xdiv.push_back(X);
        Ydiv.push_back(Y);
        while(X>0){
            X/=K;
            Xdiv.push_back(X);
        }
        while(Y>0){
            Y/=K;
            Ydiv.push_back(Y);
        }
        sort(Ydiv.begin(),Ydiv.end());
        ll ans = 1LL<<40;
        sort(Xdiv.begin(),Xdiv.end());
        rep(i,Xdiv.size()){
            auto it = lower_bound(Ydiv.begin(), Ydiv.end(), Xdiv[i]);
            if(it != Ydiv.end() && *it == Xdiv[i]){
                ans = min(ans, (ll)((Xdiv.size()-i-1) +
                 ((ll)Ydiv.size() - (lower_bound(Ydiv.begin(),Ydiv.end(),Xdiv[i]) - Ydiv.begin())-1)));
            }
        }
        cout << ans << endl;
    }
}